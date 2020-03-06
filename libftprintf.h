/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:46:41 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/05 14:57:43 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_ispercent(char c);
int		ft_get_type_char(const char *str);
int		ft_getsize(const char *str);
int		ft_print_percent_rule(const char *str, va_list *args);
void	ft_intflag(char flag, va_list *args);
void	ft_putnbr(intmax_t n);
void	ft_intflag(char flag, va_list *args);
void	ft_putnbrhex(uintmax_t n,int flag);
void	ft_uintflag(char flag, va_list *args);
void	ft_strflag(va_list *args);
void	ft_pflag(va_list *args);
int		ft_printf(const char *str, ...);

int		g_counter;

#endif
