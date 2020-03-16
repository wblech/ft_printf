/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:09:29 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/13 18:26:59 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_width(t_printf *estrutura)
{
	int dif;
	int i;
	char *new;

	i = 0;
	if (estrutura->isneg && estrutura->size_precision < 0)
	{
		update_value(estrutura, ft_strjoin("-", estrutura->value));
		update_option(estrutura, size_value, (int)ft_strlen(estrutura->value));
	}
	dif = estrutura->size_value - estrutura->width;
	if (dif < 0)
	{
		//alloca memoria com o tamanho do precision e anda com a diferença

		dif *= -1;
		//size = estrutura->width;
		new = (char *)ft_calloc((estrutura->width + 1), 1);
		ft_memset(new, ' ', estrutura->width);
		while (estrutura->value[i] != '\0')
		{
			if (estrutura->flag == '-')
				new[i] = estrutura->value[i];
			else
				new[dif] = estrutura->value[i];
			dif++;
			i++;
		}
	}
	else
	{
		new = (char *)ft_calloc((estrutura->size_value + 1), 1);
		while (estrutura->value[i] != '\0')
		{
			new[i] = estrutura->value[i];
			i++;
		}
	}
	return (new);
}

// int main (void)
// {
// 	t_printf *estrutura;
// 	char *str;
// 	str = ft_strdup("wi");

// 	estrutura = create_printf();
// 	update_value(estrutura, str);
// 	update_option(estrutura, isneg, 0);
// 	update_option(estrutura, type_char, 'i');
// 	update_option(estrutura, width, 5);
// 	update_option(estrutura, flag, '-');
// 	update_option(estrutura, size_value, (int)ft_strlen(estrutura->value));
// 	update_value(estrutura, ft_width(estrutura));
// 	printf("%s\n", estrutura->value);
// }
