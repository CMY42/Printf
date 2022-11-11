/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:01 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/11 16:53:04 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

typedef struct s_sc
{
	int	len;
	int	widht;
}			t_sc;

void	ft_printhexa(unsigned int x)
{
	char	*hexa;
	int		*res;
	int		i;

	hexa = "0123456789abcdef";
	res = malloc(100);
	i = 0;
	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar_fd(res[i], 1);
		i--;
	}
}

int	ft_intlen(int nb, char c)
{
	int	i;
	int	number;
	int	neg;

	i = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
	{
		neg = 0;
		number = nb;
	}
	if (c == 'd')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i + neg);
	}
	if (c == 'x' || c == 'X')
	{
		while (number)
		{
			number /= 16;
			i++;
		}
		return (i);
	}
	return (0);
}

const char	*ft_search_arg(va_list arg, const char *str, t_sc *sc)
{
	int				d;
	char			*s;
	unsigned int	x;

	if (*str == 'd')
	{
		d = va_arg(arg, int);
		ft_putnbr_fd(d, 1);
		(*sc).len += ft_intlen(d, *str);
	}
	else if (*str == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
		{
			write (1, "(null)", 6);
			(*sc).len += 6;
		}
		else
		{
			ft_putstr_fd(s, 1);
			(*sc).len += ft_strlen(s);
		}
	}
	else if (*str == 'x' || *str == 'X')
	{
		x = va_arg(arg, unsigned int);
		ft_printhexa((unsigned long)x);
		(*sc).len += ft_intlen((unsigned long)x, *str);
	}
	else
		return (NULL);
	str++;
	return (str);
}

const char	*ft_read_text(t_sc *sc, const char *str)
{
	char	*next;

	next = ft_strchr(str, '%');
	if (next)
	(*sc).widht = next - str;
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

	va_start (arg, str);
	t_sc sc;
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
