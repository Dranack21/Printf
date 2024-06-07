#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <stdint.h>

int ft_pointer(void *ptr);
int	ft_putchar(char c);
int	ft_hexa_upper(size_t n);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_hexa_lower(size_t n);
int ft_putunbr(int n);

int		ft_printf(const char* str, ...);

size_t	ft_strlen(const char *s);

#endif