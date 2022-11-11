/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countfor_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarras <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:32 by abarras           #+#    #+#             */
/*   Updated: 2022/11/09 14:41:02 by abarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*mettre en int i la place dans la chaine str du % a controler,
et retourne la valeur ascii du caractere suivant le % 
si la conversion est valide*/
int	ft_checkv_printf(const char *str, int i)
{
	if ((str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p'
			|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%')
		&& (str[i] == '%'))
		return (str[i + 1]);
	return (0);
}

/*compte le nombre de conversion valide et le retourne en size_t*/
size_t	ft_countfor_printf(const char	*str)
{
	size_t	f;
	int		i;

	f = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%' && ft_checkv_printf(str, i) != 0)
		{
			f++;
			i++;
		}
		i++;
	}
	return (f);
}

int	*ft_allv_printf(const char *str)
{
	int	*final;
	int	j;
	int	i;

	final = (int *)malloc(sizeof(int) * (ft_countfor_printf(str) + 1));
	if (!final)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '%')
		{
			final[i] = ft_checkv_printf(str, j);
			i++;
			j++;
		}
		j++;
	}
	final[i] = 0;
	return (final);
}

/*
int main(int argc, char **argv)
{
	argc = 1;
	printf("%lu\n", ft_countfor_printf(argv[1]));
}*/
