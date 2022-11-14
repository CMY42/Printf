/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:01 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/14 15:23:43 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

typedef struct s_sc
{
	int	len;
	int	widht;
}			t_sc;

void	ft_printhexa(unsigned int x, const char str)
{
	if (x == 0)
	{
		write (1, "0", 1);
	}
	else if (x != 0)
	{
		if (x >= 16)
		{
			ft_printhexa(x / 16, str);
			ft_printhexa(x % 16, str);
		}
		else
		{
			if (x <= 9)
				ft_putchar_fd((x + '0'), 1);
			else
			{
				if (str == 'x')
					ft_putchar_fd((x - 10 + 'a'), 1);
				if (str == 'X')
					ft_putchar_fd((x - 10 + 'A'), 1);
			}
		}
	}
}

int	ft_intlenhexa(int nb, char c)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb && (c == 'x' || c == 'X'))
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

//VALEUR RETOUR
int	ft_intlen(int nb, char c)
{
	int	i;
	int	number;
	int	neg;

	i = 0;
	if (!nb)
		return (1);
	if (nb < 0 && (c == 'd' || c == 'i'))
	{
		neg = 1;
		number = -nb;
	}
	else if (nb < 0 && (c == 'u'))
	{
		neg = 9;
	}
	else
	{
		neg = 0;
		number = nb;
	}
	if (c == 'd' || c == 'i')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i + neg);
	}
	if (c == 'u')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i + neg);
	}
	return (0);
}

const char	*ft_search_arg(va_list arg, const char *str, t_sc *sc)
{
	int				d;
	char			*s;
	unsigned int	x;
	int				c;
	unsigned int	u;

	if (*str == 'd' || *str == 'i')
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
		ft_printhexa((unsigned long)x, *str);
		(*sc).len += ft_intlenhexa((unsigned long)x, *str);
	}
	else if (*str == 'c')
	{
		c = va_arg(arg, int);
		write(1, &c, 1);
		(*sc).len += 1;
	}
	else if (*str == '%')
	{
		write(1, "%", 1);
		(*sc).len += 1;
	}
	else if (*str == 'u')
	{
		u = va_arg(arg, unsigned int);
		ft_putnbru_fd(u, 1);
		(*sc).len += ft_intlen(u, *str);
	}
	else
		return (NULL);
	str++;
	return (str);
}

//CAS OU PAS DE % OU VIENT APRES
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
