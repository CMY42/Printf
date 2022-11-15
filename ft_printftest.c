/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:38:28 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/15 16:38:28 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef struct s_sc
{
	int	len;
	int	widht;
}			t_sc;

const char	*ft_search_arg(va_list arg, const char *str, t_sc *sc)
{
	if (*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X' )
	{
		*ft_search_arg_1(va_list arg, const char *str, t_sc *sc)
	}
	else if (*str == 's')
	{
		*ft_search_arg_2(va_list arg, const char *str, t_sc *sc)
	}
	else if (*str == 'c' || *str == 'u' || *str == 'p')
	{
		*ft_search_arg_3(va_list arg, const char *str, t_sc *sc)
	}
	else if (*str == '%')
	{
		write(1, "%", 1);
		(*sc).len += 1;
	}
	else
		return (NULL);
	str++;
	return (str);
}

const char	*ft_read_text(t_sc *sc, const char *str)
{
	char	*prev;

	prev = ft_strchr(str, '%');
	if (prev)
	(*sc).widht = prev - str;
	else
	(*sc).widht = ft_strlen(str);
	write(1, str, (*sc).widht);
	(*sc).len += (*sc).widht;
	while (*str && *str != '%')
	str++;
	return (str);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_sc	sc;

	va_start (arg, str);
	sc.len = 0;
	sc.widht = 0;
	while (*str)
	{
		if (*str == '%')
		str = ft_search_arg(arg, str + 1, &sc);
		else
		str = ft_read_text(&sc, str);
		if (!str)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.len);
		}
	}
	va_end(arg);
	return (sc.len);
}
