/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_arg_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:59:48 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 14:34:20 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_arg_3(va_list arg, const char *str, int len)
{
	int				c;
	unsigned int	u;
	unsigned long	p;

	if (*str == 'c')
	{
		c = va_arg(arg, int);
		write(1, &c, 1);
		len += 1;
	}
	else if (*str == 'u')
	{
		u = va_arg(arg, unsigned int);
		ft_putnbru_fd(u, 1);
		len += ft_intlenu(u);
	}
	else if (*str == 'p')
	{
		p = va_arg(arg, unsigned long long);
		len += ft_printp((unsigned long long)p, *str);
	}
	return (len);
}
