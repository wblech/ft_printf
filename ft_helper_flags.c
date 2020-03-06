/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:56:53 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/06 16:11:49 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_setflag(const char *str, va_list *args)
{
	int i;
	int size;

typedef struct 	t_elm
{
	char 		flag;
	int			width;
	int			precision;
}				t_printf;

t_printf estrutura;

	size = ft_getsize(str);
	i = 1;
	if (ft_isflag(str[i]))
		estrutura.flag = str[i++];
	if (ft_isnum(str[i]))
	{
		estrutura.width = ft_atoi(str[i]);
		i =+ ft_strlen_nbr(estrutura.width);
	}
	if (str[i] == '*')
	{
		estrutura.width = va_arg(*args, int);
		i++;
	}
	if (str[i] == '.')
	{
		if (ft_isnum(str[++i]))
		{
			estrutura.precision = ft_atoi(str[i]);
			i =+ ft_strlen_nbr(estrutura.precision);
		}
		else
		{
			estrutura.precision = 0;
			i++;
		}
	}


}
