/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:30:28 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/05 11:41:14 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnbr(intmax_t n)
{
	unsigned int nbr;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void		ft_intflag(char flag, va_list *args)
{
	int n;

	n = va_arg(*args, int);
	if (flag == 'c')
		ft_putchar(n);
	if (flag == 'd' || flag == 'i')
		ft_putnbr(n);
}
