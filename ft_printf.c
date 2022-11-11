/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:01 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/08 15:32:17 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
/*#include "libftprintf.h"*/

int ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	while (str > 0)
	{
		int i;

		i = va_arg(args, int);
		printf("d.\n", i);
		--str;
	}
	va_end(args);
}

int main()
{
	/*printf("%.5s", "Hello World");*/
	ft_printf("Hello World");
}
