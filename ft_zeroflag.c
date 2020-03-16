/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:35:02 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/13 18:27:14 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_zeroflag(t_printf *estrutura)
{
	int dif;
	int i;
	int t;
	char *new;

	i = 0;
	t = 0;
	dif = estrutura->size_value - estrutura->size_zeroflag;
	if (dif <= 0)
	{
		dif *= -1;
		//size = estrutura->size_zeroflag + estrutura->isneg;
		new = (char *)ft_calloc((estrutura->size_zeroflag + 1), 1);
		ft_memset(new, '0', estrutura->size_zeroflag);
		while (estrutura->value[i] != '\0')
		{
			new[(estrutura->isneg) ? dif + 1 : dif] = estrutura->value[i];
			dif++;
			i++;
		}
	}
	else
	{
		i = (estrutura->isneg) ? i + 1 : 0;
		new = (char *)ft_calloc((estrutura->size_value + 1), 1);
		while (estrutura->value[t] != '\0')
			new[i++] = estrutura->value[t++];
	}
	if (estrutura->isneg)
		new[0] = '-';
	return (new);
}

// int main (void)
// {
// 	t_printf *estrutura;
// 	char *str;
// 	str = ft_strdup("15");

// 	estrutura = create_printf();
// 	update_value(estrutura, str);
// 	update_option(estrutura, isneg, 1);
// 	update_option(estrutura, type_char, 'i');
// 	update_option(estrutura,>size_zeroflag, 10);
// 	update_option(estrutura, flag, '0');
// 	update_option(estrutura, size_value, (int)ft_strlen(estrutura->value) + estrutura->isneg);
// 	update_value(estrutura, ft_zeroflag(estrutura));
// 	printf("%s\n", estrutura->value);
// }
