/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:28:05 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/05 14:56:33 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_counter++;
}

void	ft_putstr(char *str)
{
	int i;

	i= 0;
	while(str[i] != '\0')
		ft_putchar(str[i++]);
}

int		ft_print_percent_rule(const char *str, va_list *args)
{
	char flag;

	flag = ft_get_type_char(str);
	if (flag == 'c' || flag == 'd' || flag == 'i')
		ft_intflag(flag, args);
	if (flag == 'u' || flag == 'x' || flag == 'X')
	 	ft_uintflag(flag, args);
	if (flag == 's')
		ft_strflag(args);
	if (flag == 'p')
		ft_pflag(args);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int i;
	int nextflag;
	int thisflag;
	va_list args;

	g_counter = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if ((ft_ispercent(str[i])) && !(ft_ispercent(str[i + 1])) &&
		!(ft_ispercent(str[((i - 1) < 0) ? i : i - 1])))
			i += ft_print_percent_rule(&str[i], &args);
		else if ((ft_ispercent(str[i]) && ft_ispercent(str[i + 1])) ||
		(!ft_ispercent(str[i])))
			ft_putchar(str[i]);
		i++;
	}
	return (g_counter);
}
