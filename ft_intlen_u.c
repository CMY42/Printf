/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:27:42 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 14:15:45 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlenu(int nb)
{
	int	i;
	int	number;

	i = 0;
	if (!nb)
		return (1);
	if (nb < 0)
		return (10);
	else
	number = nb;
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i);
}
