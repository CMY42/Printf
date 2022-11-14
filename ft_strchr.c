/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:30:09 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/14 10:26:48 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/*int main ()
{
	char *s = "Hello World";
	printf("%s\n", (ft_strchr(s, 'W')));
	printf("%s\n", (strchr(s, 'W')));
}*/
