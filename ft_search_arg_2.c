/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_arg_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:12:59 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/15 17:12:59 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_search_arg_2(va_list arg, const char *str, t_sc *sc)
{
	char			*s;
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
}
