/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:57:22 by habouda           #+#    #+#             */
/*   Updated: 2024/06/10 21:03:22 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(int n)
{
	int					i;
	static unsigned int	k;

	i = 0;
	if (n >= 0)
		return (ft_putnbr(n));
	if (n < 0)
	{
		k = (unsigned int)n;
	}
	while (k >= 10)
	{
		i = i + ft_putnbr(k / 10);
		k = k % 10;
	}
	ft_putchar(k + 48);
	i++;
	return (i);
}
