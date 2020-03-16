/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:06:39 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/13 18:27:26 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*ft_precision_nbr(t_printf *estrutura)
{
	int dif;
	int i;
	int t;
	int size;
	char *new;

	i = 0;
	t = 0;
	dif = estrutura->size_value - estrutura->size_precision;
	if (dif <= 0)
	{
		dif *= -1;
		size = estrutura->size_precision + estrutura->isneg;
		new = (char *)ft_calloc((size + 1), 1);
		ft_memset(new, '0', size);
		while (estrutura->value[i] != '\0')
		{
			new[(estrutura->isneg) ? dif + 2 : dif] = estrutura->value[i];
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

static	char	*ft_precision_str(t_printf *estrutura)
{
	int len;
	char *new;
	int i;

	i = 0;
	len = estrutura->size_precision;
	new = (char *)ft_calloc((len + 1), 1);
	ft_strncpy(new, estrutura->value, len);
	return (new);
}

char	*ft_precision(t_printf *estrutura)
{
	int spec;
	int size_precision;
	char *value;

	size_precision = estrutura->size_precision;
	value = estrutura->value;
	spec = estrutura->type_char;
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X')
	{
		if (ft_atoi(value) == 0 && size_precision == 0)
			return (ft_strdup(""));
		else
			return (ft_precision_nbr(estrutura));
	}
	if (spec == 's')
		return (ft_precision_str(estrutura));
	return (value);
}

// int main (void)
// {
// 	t_printf *estrutura;
// 	char *str;
// 	str = ft_strdup("155");

// 	estrutura = create_printf();
// 	update_value(estrutura, str);
// 	update_option(estrutura, isneg, 1);
// 	update_option(estrutura, type_char, 'i');
// 	update_option(estrutura, size_precision, 5);
// 	update_option(estrutura, size_value, (int)ft_strlen(estrutura->value) + estrutura->isneg);
// 	update_value(estrutura, ft_precision(estrutura));
// 	printf("%s\n", estrutura->value);
// }
