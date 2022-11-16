/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_arg_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:59:19 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 14:15:07 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_arg_1(va_list arg, const char *str, int len)
{
	int				d;
	unsigned int	x;

	if (*str == 'd' || *str == 'i')
	{
		d = va_arg(arg, int);
		ft_putnbr_fd(d, 1);
		len += ft_intlenid(d);
	}
	else if (*str == 'x' || *str == 'X')
	{
		x = va_arg(arg, unsigned long);
		ft_printhexa((unsigned long long)x, *str);
		len += ft_intlenhexa((unsigned long)x);
	}
	return (len);
}
