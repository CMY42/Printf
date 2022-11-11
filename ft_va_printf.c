/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarras <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:14:37 by abarras           #+#    #+#             */
/*   Updated: 2022/11/09 14:53:39 by abarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_tohexa_printf(int f)
{
	
}*/

int	ft_printf(const char *str, ...)
{
	int		*tab;
	int		i;

	va_list(ap);
	va_start(ap, str);
	tab = ft_allv_printf(str);
	i = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (tab[i] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (tab[i] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else if (tab[i] == 'i' || tab[i] == 'd')
				ft_putnbr_fd(va_arg(ap, int), 1);
			i++;
			str += 2;
		}
		else
			write(1, &*str++, 1);
	}
	free(tab);
	va_end(ap);
	return (0);
}
/*
int main()
{
	ft_printf("yo%c %s %i %d fin du str\n", 117, "salut", 789, 101112);
	printf("\n%i\n", 20 / 16); 
}*/
