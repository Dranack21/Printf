/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:36 by habouda           #+#    #+#             */
/*   Updated: 2024/06/05 15:16:39 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_upper(int n)
{
	char	*charset;
	char	*stash;
	int		i;

	i = 8;
	charset = "0123456789ABCDEF";
	stash = malloc(9 * sizeof(char));
	stash[8] = '\0';
	while (n)
	{
		stash[--i] = (charset[n % 16]);
		n = n / 16;
	}
	ft_putstr(stash + i);
	free (stash);
	stash = NULL;
	return (8 - i);
}

int	ft_hexa_lower(int n)
{
	char	*charset;
	char	*stash;
	int		i;

	i = 8;
	charset = "0123456789abcdef";
	stash = malloc(9 * sizeof(char));
	stash[8] = '\0';
	while (n)
	{
		stash[--i] = (charset[n % 16]);
	}
	ft_putstr(stash + i);
	free (stash);
	stash = NULL;
	return (8 - i);
}

