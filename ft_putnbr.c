/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:57:22 by habouda           #+#    #+#             */
/*   Updated: 2024/06/05 14:22:23 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return ((write(1, "-2147483648", 11)),11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			i++;
			n = -n;
		}
		while (n >= 10)
		{
			ft_putnbr(n / 10);
			i++;
			n = n % 10;
		}
		ft_putchar(n + 48);
		i++;
	}
	return (i);
}
