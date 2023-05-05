/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:15:02 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/05 18:01:17 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_format(char format)
{
	if (format == 'd' || format == 'i')
		return (1);
	else if (format == 'x')
		return (2);
	else if (format == 'X')
		return (3);
	else if (format == 'p')
		return (4);
	else if (format == 's')
		return (5);
	else if (format == 'c')
		return (6);
	else if (format == 'u')
		return (7);
	else if (format == '%')
		return (8);
	return (0);
}

void	ft_format_create(int n, va_list ptr, int *tol)
{
	if (n <= 0 && n >= 9)
		return ;
	else if (n == 5)
		ft_putstr(va_arg(ptr, char *), tol);
	else if (n == 1)
		ft_putnbr(va_arg(ptr, int), tol);
	else if (n == 2)
		ft_lowerhex(va_arg(ptr, unsigned int), tol);
	else if (n == 3)
		ft_upperhex(va_arg(ptr, unsigned int), tol);
	else if (n == 4)
		ft_hexp(va_arg(ptr, void *), tol);
	else if (n == 6)
		ft_putchar(va_arg(ptr, int), tol);
	else if (n == 7)
		ft_putunsigned(va_arg(ptr, unsigned int), tol);
	else if (n == 8)
		ft_putchar('%', tol);
}

int	work_search(char *str, va_list args, int tol)
{
	while (*str)
	{
		while (*str != '%' && *str)
		{
			ft_putchar(*str, &tol);
			str++;
		}
		if (*str && ft_get_format(*(str + 1)) > 0)
		{
			ft_format_create(ft_get_format(*(str + 1)), args, &tol);
			str++;
		}
		if (!(*str))
			break ;
		str++;
	}
	return (tol);
}

int	ft_printf(const char *format, ...)
{
	int		tol;
	va_list	args;

	if (!format)
		return (-1);
	tol = 0;
	va_start(args, format);
	tol = work_search((char *)format, args, tol);
	va_end(args);
	return (tol);
}
