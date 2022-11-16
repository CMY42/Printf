/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:40:25 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 14:15:42 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa(unsigned long long x, const char str)
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
				if (str == 'x' || str == 'p')
					ft_putchar_fd((x - 10 + 'a'), 1);
				if (str == 'X')
					ft_putchar_fd((x - 10 + 'A'), 1);
			}
		}
	}
}
