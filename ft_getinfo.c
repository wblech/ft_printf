/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:00:47 by wbertoni          #+#    #+#             */
/*   Updated: 2020/03/13 19:09:46 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Function: ft_create_flag
** -------------------------
** Description: Update the value "flag" inside the structure elem.
** If the flag is '0' but the next char is the flag '-', the char '-'
** will be save in the flag value inside the structure.
**
** elem: the pointer to the structure
** str: the string with the flag
** i: the index where the flag is inside the string
**
** Return: how many positions the flag use inside the string
*/

int		static		ft_create_flag(t_printf *elem, char *str, int i)
{
	if (str[i] == '0')
	{
		if (str[i + 1] == '-')
		{
			update_option(elem, flag, '-');
			return (i + 2);
		}
		else
			update_option(elem, flag, str[i++]);
	}
	else
		update_option(elem, flag, str[i++]);
	return (i);
}

int		static		ft_create_flag_size(t_printf *elem, char *str, int i,
va_list *args)
{
	int nbr;

	nbr = 0;
	if (elem->flag == '0')
		update_option(elem, size_zeroflag, (nbr = ft_getnumber(&str[i], args)));
	else
		update_option(elem, width, (nbr = ft_getnumber(&str[i], args)));
	i += (str[i] == '*') ? 1 : ft_getnbrsize(nbr);
	return (i);
}

int		static		ft_create_precision(t_printf *elem, char *str, int i,
va_list *args)
{
	int nbr;

	nbr = 0;
	i++;
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		update_option(elem, size_precision, (nbr = ft_getnumber(&str[i], args)));
		i += (str[i] == '*') ? 1 : ft_getnbrsize(nbr);
	}
	else
		update_option(elem, size_precision, 0);
	return (i);
}

void	static		ft_create_value(t_printf *elem, char *str, va_list *args,
int i)
{
	if (str[i] == 'c' ||str[i] == 's' || str[i] == 'p' || str[i] == 'd'
	||str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
	{
		update_option(elem, type_char, str[i]);
		ft_getvalue(elem, args);
	}
	else if (str[i] == '%')
	{
		update_option(elem, type_char, '%');
		update_value(elem, ft_strdup("%"));
	}
	else
		update_option(elem, type_char, 'y');
}

/*
** Function: ft_getinfo
** ---------------------
**
** Description: Gets the information after '%' in the string. Get the flag,
** width and precision and update the structure with those information.
**
** str : the position of the '%' to be read
** elem: th structure to be updated
** args: the args from the variadic function
**
** Return: the size from the '%' until the spec(d,i,u,p,s,c,x,X).
** If doesn´t have a spec it will return 'y'
*/

int		ft_getinfo(char *str, t_printf *elem, va_list *args)
{
	int i;

	i = 1;
	if (str[i] == '0' || str[i] == '-')
		i = ft_create_flag(elem, str, i);
	if (ft_isdigit(str[i]) || str[i] == '*')
		i = ft_create_flag_size(elem, str, i, args);
	if (str[i] == '.')
		i = ft_create_precision(elem, str, i, args);
	ft_create_value(elem, str, args, i);
	return (i);
}
