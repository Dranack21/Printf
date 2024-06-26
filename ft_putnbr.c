/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:57:22 by habouda           #+#    #+#             */
/*   Updated: 2024/06/10 21:01:50 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return ((write(1, "-2147483648", 11)), 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			i = 1;
			n = -n;
		}
		while (n >= 10)
		{
			i = i + ft_putnbr(n / 10);
			n = n % 10;
		}
		i = i + ft_putchar(n + 48);
	}
	return (i);
}
