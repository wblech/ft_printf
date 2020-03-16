/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:48:26 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/13 18:28:03 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	static	ft_getvalue_d_i(t_printf *elem, va_list *args)
{
	int intvalue;

	intvalue = va_arg(*args, int);
	if (intvalue < 0)
	{
		update_option(elem, isneg, 1);
		intvalue *= -1;
	}
	update_value(elem, ft_itoa(intvalue));
}

void			ft_getvalue(t_printf *elem, va_list *args)
{
	int 	i;

	i = 0;
	if (elem->type_char == 's')
		update_value(elem, va_arg(*args, char*));
	if (elem->type_char == 'd' || elem->type_char == 'i')
		ft_getvalue_d_i(elem, args);
	if (elem->type_char == 'c')
		update_value(elem, ft_chartostr(va_arg(*args, int)));
	if (elem->type_char == 'x')
		update_value(elem, ft_itoa_base(va_arg(*args, unsigned int), 16));
	if (elem->type_char == 'X')
		update_value(elem, ft_strupper(ft_itoa_base(va_arg(*args, unsigned int),
		16)));
	if (elem->type_char == 'u')
		update_value(elem, ft_itoa_base(va_arg(*args, unsigned int), 10));
	if (elem->type_char == 'p')
		update_value(elem, ft_strjoin("0x", ft_itoa_base(va_arg(*args, uintptr_t)
		,16)));
	if (elem->type_char == 'y')
		update_value(elem, ft_strdup(""));
}
