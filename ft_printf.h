/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:03:53 by habouda           #+#    #+#             */
/*   Updated: 2024/06/17 14:25:33 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_pointer(void *ptr);
int		ft_putchar(char c);
int		ft_hexa_upper(size_t n);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_hexa_lower(size_t n);
int		ft_putunbr(int n);
int		ft_printf(const char *str, ...);

size_t	ft_strlen(const char *s);
#endif