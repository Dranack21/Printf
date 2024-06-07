/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:36 by habouda           #+#    #+#             */
/*   Updated: 2024/06/07 17:28:33 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_upper(size_t num)
{
	char			*charset;
	char			*stash;
	int				i;
	unsigned int	n;

	n = (unsigned int)num;
	i = 8;
	charset = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putstr("0"), 1);
	stash = malloc(9 * sizeof(char));
	stash[8] = '\0';
	while (n)
	{
		stash[--i] = (charset[n % 16]);
		n = n / 16;
	}
	ft_putstr(stash + i);
	return (free (stash), 8 - i);
}

int	ft_hexa_lower(size_t num)
{
	char			*charset;
	char			*stash;
	int				i;
	unsigned int	n;

	n = (unsigned int)num;
	i = 8;
	charset = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr("0"), 1);
	stash = malloc(9 * sizeof(char));
	stash[8] = '\0';
	while (n)
	{
		stash[--i] = (charset[n % 16]);
		n = n / 16;
	}
	ft_putstr(stash + i);
	return (free (stash), 8 - i);
}
