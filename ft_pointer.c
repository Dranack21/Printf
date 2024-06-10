/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:21:00 by habouda           #+#    #+#             */
/*   Updated: 2024/06/10 21:03:37 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chungli(size_t num)
{
	char			*charset;
	char			*stash;
	int				i;
	unsigned long	n;

	n = (unsigned long)num;
	i = 16;
	charset = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr("0"), 1);
	stash = malloc(17 * sizeof(char));
	stash[16] = '\0';
	while (n)
	{
		stash[--i] = (charset[n % 16]);
		n = n / 16;
	}
	ft_putstr(stash + i);
	return (free (stash), 16 - i);
}

int	ft_pointer(void *ptr)
{
	int	i;

	if (!ptr)
		return (write(1, "(nil)", 5));
	i = 2;
	write(1, "0x", 2);
	i = i + ft_chungli((size_t)ptr);
	return (i);
}
