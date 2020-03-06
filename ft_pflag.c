/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pconv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:39:03 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/05 11:42:46 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pflag(va_list *args)
{
	uintptr_t ptr;

	ptr = va_arg(*args, uintptr_t);
	ft_putstr("0x");
	ft_putnbrhex(ptr, 'x');
}
