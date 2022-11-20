/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:14:38 by hel-haia          #+#    #+#             */
/*   Updated: 2022/11/20 14:14:36 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	if (write(1, &c, 1))
	{
		*len += 1;
		return ;
	}
	*len = -1;
}

void	ft_putstr(char *s, int *len)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, len);
		s++;
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

void	ft_putunsigned(unsigned int n, int *len)
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
