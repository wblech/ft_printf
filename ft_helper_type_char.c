/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_type_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:51:15 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/05 14:57:43 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_getsize(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 'c' ||str[i] != 's' || str[i] != 'p' || str[i] != 'd'
	||str[i] != 'i' || str[i] != 'u' || str[i] != 'x' || str[i] != 'X')
	{
		i++;
	}
	return (i);
}

int		ft_ispercent(char c)
{
	return ((c == '%') ? 1 : 0);
}

int		ft_get_type_char(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'c')
			return ('c');
		if (str[i] == 's')
			return ('s');
		if (str[i] == 'p')
			return ('p');
		if (str[i] == 'd')
			return ('d');
		if (str[i] == 'i')
			return ('i');
		if (str[i] == 'u')
			return ('u');
		if (str[i] == 'x')
			return ('x');
		if (str[i] == 'X')
			return ('X');
		i++;
	}
	return (0);
}
