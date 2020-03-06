/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:33:44 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/05 11:44:20 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnbrhex(uintmax_t n,int flag)
{
	if (n >= 16)
		ft_putnbrhex(n / 16, flag);
	if ((n % 16) >= 10)
		ft_putchar(((n % 16) - 10) + ((flag == 'x') ? 'a' : 'A'));
	else
		ft_putchar((n % 16) + '0');
}

void		ft_uintflag(char flag, va_list *args)
{
	unsigned int n;

	n = va_arg(*args, unsigned int);
	if (flag == 'u')
		ft_putnbr(n);
	if (flag == 'x')
		ft_putnbrhex(n, flag);
	if (flag == 'X')
		ft_putnbrhex(n, flag);
}
