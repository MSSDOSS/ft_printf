/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:14:38 by hel-haia          #+#    #+#             */
/*   Updated: 2023/04/02 20:10:00 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *tol)
{
	if (write(1, &c, 1))
	{
		*tol += 1;
		return ;
	}
	else
		*tol = -1;
}

void	ft_putstr(char *str, int *tol)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*tol += 6;
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, tol);
		str++;
	}
}

void	ft_putnbr(int n, int *len)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		*len += 1;
		ft_putnbr(-n, len);
	}
	else if (n >= 0 && n <= 9 && *len > -1)
	{
		c = n + 48;
		write (1, &c, 1);
		*len += 1;
	}
	else if (n > 0)
	{
		ft_putnbr (n / 10, len);
		ft_putnbr (n % 10, len);
	}
}

void	ft_putunsigned(unsigned long n, int *len)
{
	if (n < 0)
	{
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + '0', len);
}
