/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:15:43 by hel-haia          #+#    #+#             */
/*   Updated: 2023/04/28 23:13:40 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_format_create(int n, va_list args, int *tol);
int		ft_get_format(char format);
void	ft_upperhex(unsigned int n, int *tol);
void	ft_lowerhex(unsigned long n, int *tol);
void	ft_hexp(void *ptr, int *len);
void	ft_putchar(char c, int *tol);
void	ft_putnbr(int n, int *len);
void	ft_putunsigned(unsigned long n, int *len);
void	ft_putstr(char *str, int *tol);

#endif