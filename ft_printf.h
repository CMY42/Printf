/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:34:14 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 14:34:13 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_intlenhexa(unsigned long long nb);
int		ft_intlenid(int nb);
int		ft_intlenu(int nb);
void	ft_printhexa(unsigned long long x, const char str);
int		ft_printp(unsigned long long p, const char str);
int		ft_search_arg_1(va_list arg, const char *str, int len);
int		ft_search_arg_2(va_list arg, int len);
int		ft_search_arg_3(va_list arg, const char *str, int len);
void	ft_putnbru_fd(unsigned int n, int fd);

#endif
