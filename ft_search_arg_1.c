/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_arg_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:59:19 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/15 16:59:19 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_search_arg_1(va_list arg, const char *str, t_sc *sc)
{
	int				d;
	unsigned int	x;

	if (*str == 'd' || *str == 'i')
	{
		d = va_arg(arg, int);
		ft_putnbr_fd(d, 1);
		(*sc).len += ft_intlen(d, *str);
	}
	else if (*str == 'x' || *str == 'X')
	{
		x = va_arg(arg, unsigned long);
		ft_printhexa((unsigned long long)x, *str);
		(*sc).len += ft_intlenhexa((unsigned long)x);
	}
}
