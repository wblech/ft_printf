/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wblech <Wblech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:55:39 by Wblech            #+#    #+#             */
/*   Updated: 2020/03/23 18:30:29 by Wblech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFFTPRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef enum e_names
{
  value,
  size_precision,
  flag,
  width,
  size_zeroflag,
  size_value,
  type_char,
  isneg
} t_names;

typedef struct s_printf
{
  char *value;
  int size_precision;
  int flag;
  int width;
  int size_zeroflag;
  int size_value;
  int type_char;
  int isneg;
} t_printf;

t_printf *create_printf(void);
void update_value(t_printf *elem, char *str);
void update_option(t_printf *elem, t_names name, int opt);
void del_elem(t_printf *elem);
void ft_putchar(char c);
void ft_putstr(char *str);
char *ft_strupper(char *str);
char *ft_precision(t_printf *estrutura);
char *ft_width(t_printf *estrutura);
char *ft_zeroflag(t_printf *estrutura);
unsigned int ft_getnumber(char *str, va_list *args);
unsigned int ft_getnbrsize(unsigned int nbr);
void static ft_polish(t_printf *elem);
int ft_print_percent_rule(char *str, va_list *args);
int ft_printf(const char *str, ...);
int ft_getinfo(char *str, t_printf *elem, va_list *args);
void ft_getvalue(t_printf *elem, va_list *args);

int g_counter;

#endif
