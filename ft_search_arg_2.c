/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_arg_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:12:59 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 14:15:04 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_arg_2(va_list arg, int len)
{
	char			*s;

	s = va_arg(arg, char *);
	if (!s)
	{
		write (1, "(null)", 6);
		len += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		len += ft_strlen(s);
	}
	return (len);
}
