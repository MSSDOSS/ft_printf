/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:12:06 by hel-haia          #+#    #+#             */
/*   Updated: 2022/11/20 19:22:41 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatgetter(char text)
{
	if (text == 'd' || text == 'i')
		return (1);
	else if (text == 'x')
		return (2);
	else if (text == 'X')
		return (3);
	else if (text == 'p')
		return (4);
	else if (text == 's')
		return (5);
	else if (text == 'c')
		return (6);
	else if (text == 'u')
		return (7);
	else if (text == '%')
		return (8);
	return (0);
}

void	ft_print_format(int format, va_list ptr, int *len)
{
	if (format <= 0 && format >= 9)
		return ;
	else if (format == 5)
		ft_putstr(va_arg(ptr, char *), len);
	else if (format == 1)
		ft_putnbr(va_arg(ptr, int), len);
	else if (format == 2)
		ft_lowerhex(va_arg(ptr, unsigned int), len);
	else if (format == 3)
		ft_upperhex(va_arg(ptr, unsigned int), len);
	else if (format == 4)
		ft_hexp(va_arg(ptr, void *), len);
	else if (format == 6)
		ft_putchar(va_arg(ptr, int), len);
	else if (format == 7)
		ft_putunsigned(va_arg(ptr, unsigned int), len);
	else if (format == 8)
		ft_putchar('%', len);
}
