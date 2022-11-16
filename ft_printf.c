/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:38:28 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 13:56:51 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_arg(va_list arg, const char *str, int len)
{
	if (*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X' )
	{
		len = ft_search_arg_1(arg, str, len);
	}
	else if (*str == 's')
	{
		len = ft_search_arg_2(arg, len);
	}
	else if (*str == 'c' || *str == 'u' || *str == 'p')
	{
		len = ft_search_arg_3(arg, str, len);
	}
	else if (*str == '%')
	{
		write(1, "%", 1);
		len += 1;
	}
	return (len);
}

int	ft_strnull(va_list arg, int len)
{
	write(1, "(null)", 6);
	va_end(arg);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	va_start (arg, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			len = ft_search_arg(arg, str + 1, len);
			str += 2;
		}
		else
		{
			write(1, &*str++, 1);
			len ++;
		}
		if (!str)
		{
			ft_strnull(arg, len);
		}
	}
	va_end(arg);
	return (len);
}
