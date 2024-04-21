#include "ft_printf.h"

int	print_char(char c)
{
	ssize_t	printed_letter;

	printed_letter = write(1, &c, 1);
	return ((int)(printed_letter));
}

int	print_str(char *s)
{
	ssize_t	printed_letter;

	if (!s)
		printed_letter = write(1, "(null)", 6);
	else
		printed_letter = write(1, s, ft_strlen(s));
	return ((int)printed_letter);
}