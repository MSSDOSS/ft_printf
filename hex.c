/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:12:06 by hel-haia          #+#    #+#             */
/*   Updated: 2023/04/02 18:31:17 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upperhex(unsigned int n, int *tol)
{
	if (n <= 15 && *tol != -1)
	{
		ft_putchar("0123456789ABCDEF"[n], tol);
	}
	else if (n > 15)
	{
		ft_upperhex(n / 16, tol);
		ft_upperhex(n % 16, tol);
	}
}

void	ft_lowerhex(unsigned long n, int *tol)
{
	if (n <= 15 && *tol != -1)
	{
		ft_putchar("0123456789abcdef"[n], tol);
	}
	else if (n > 15)
	{
		ft_lowerhex(n / 16, tol);
		ft_lowerhex(n % 16, tol);
	}
}

void	ft_hexp(void *ptr, int *len)
{
	ft_putstr("0x", len);
	ft_lowerhex((unsigned long)ptr, len);
}
