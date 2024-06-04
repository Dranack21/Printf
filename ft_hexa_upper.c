/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:36 by habouda           #+#    #+#             */
/*   Updated: 2024/06/04 14:02:02 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void reverseString(char* str) 
{
    int		len;
 	char*	start;
	char*	end;
	
	len = ft_strlen(str);
    start= str;
    end = str + len - 1;
    while (start < end) 
	{
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


int	get_size(int n)
{
	int i;
	int	k;

	i = 0;
	k = 0;
	while (n > 0)
	{
		n = n / 10;
		k++;
	}
	return (k);
}


void	ft_hexa_upper(int n)
{
	char	*charset;
	char	*stash;
	int		i;

	i = 0;
	charset = "0123456789ABCDEF";
	stash = malloc(get_size(n) + 1 * sizeof(char));
	while (n)
	{
		stash[i] = (charset[n % 16]);
		n = n / 16;
		i++;
	}
	stash[i] = '\0';
	reverseString(stash);
	ft_putstr(stash);
}

void	ft_hexa_lower(int n)
{
	char	*charset;
	char	*stash;
	int		i;

	i = 0;
	charset = "0123456789abcdef";
	stash = malloc(get_size(n) + 1 * sizeof(char));
	while (n)
	{
		stash[i] = (charset[n % 16]);
		n = n / 16;
		i++;
	}
	stash[i] = '\0';
	reverseString(stash);
	ft_putstr(stash);
}


