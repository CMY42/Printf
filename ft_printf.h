/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:34:14 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/16 14:17:00 by cmansey          ###   ########.fr       */
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
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	ft_putnbru_fd(unsigned int n, int fd);
int		ft_intlenhexa(unsigned long long nb);
int		ft_intlenid(int nb);
int		ft_intlenu(int nb);
void	ft_printhexa(unsigned long long x, const char str);
int		ft_printp(unsigned long long p, const char str);
int		ft_search_arg_1(va_list arg, const char *str, int len);
int		ft_search_arg_2(va_list arg, int len);
int		ft_search_arg_3(va_list arg, const char *str, int len);

#endif
