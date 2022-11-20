/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:15:43 by hel-haia          #+#    #+#             */
/*   Updated: 2022/11/19 19:00:03 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_putchar(char c, int *len);
int		ft_printf(const char *format, ...);
void	ft_putnbr(int n, int *len);
void	ft_putunsigned(unsigned int n, int *len);
void	ft_lowerhex(unsigned long int n, int *len);
void	ft_hexp(void *ptr, int *len);
void	ft_upperhex(unsigned int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_print_format(int format, va_list args, int *len);
int		ft_formatgetter(char text);

#endif