/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:15:02 by hel-haia          #+#    #+#             */
/*   Updated: 2022/11/20 16:35:38 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upperhex(unsigned int n, int *len)
{
	if (n <= 15 && *len != -1)
	{
		ft_putchar("0123456789ABCDEF"[n], len);
	}
	else if (n > 15)
	{
		ft_upperhex(n / 16, len);
		ft_upperhex(n % 16, len);
	}
}

void	ft_lowerhex(unsigned long int n, int *len)
{
	if (n <= 15 && *len != -1)
	{
		ft_putchar("0123456789abcdef"[n], len);
	}
	else if (n > 15)
	{
		ft_lowerhex(n / 16, len);
		ft_lowerhex(n % 16, len);
	}
}

void	ft_hexp(void *ptr, int *len)
{
	ft_putstr("0x", len);
	ft_lowerhex((unsigned long int)ptr, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			ft_putchar(*format, &len);
			format++;
		}
		if (*format && ft_formatgetter(*(format + 1)) > 0)
		{
			ft_print_format(ft_formatgetter(*(format + 1)), args, &len);
			format++;
		}
		if (!(*format))
			break ;
		format++;
	}
	va_end(args);
	return (len);
}
