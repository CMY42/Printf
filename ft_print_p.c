/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:42:05 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 14:15:38 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(unsigned long long p, const char str)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (p == 0)
		i += write(1, "0", 1);
	else
	{
		ft_printhexa(p, str);
		i += ft_intlenhexa((unsigned long) p);
	}
	return (i);
}
