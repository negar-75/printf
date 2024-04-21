# ifndef FT_PRINTF_F
# define FT_PRINTF_F

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int print_char(char c);
int print_number(int num);
int print_str(char *s);
char *ft_utoa(unsigned nbr);
int print_unsigned(unsigned num);
int print_pointer (void *ptr);
char* convert_hex(unsigned long num,char format);
int print_hex(unsigned int num,char format);
int	format_validation(const char* format);
int ft_printf(const char *, ...);

# endif
