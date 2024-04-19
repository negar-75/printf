#include "ft_printf.h"

int	print_char(char c)
{
	ssize_t	printed_letter;

	printed_letter = write(1, &c, 1);
	return ((int)(printed_letter));
}

int	print_str(char *s)
{
	ssize_t printed_letter;

	if (!s)
		printed_letter = write(1, "(null)", 6);
	else
		printed_letter = write(1, s, ft_strlen(s));
	return ((int)printed_letter);
}
int print_number(int num)
{
	char	*str_num;
	int			len;
    
	str_num = ft_itoa(num);
	if(!str_num)
		return (-1);
	len = print_str(str_num);
	free(str_num);
	return len;
}

int	print_unsigned(unsigned num)
{
	char *str_num;
	int len;

	str_num = ft_utoa(num);
	if(!str_num)
		return (-1);
	len = print_str(str_num);
	free(str_num);
	return len;
}

int	print_hex(unsigned int num, char format)
{
	char	*str_num;
	int			len;

	str_num = convert_hex(num, format);
	if(!str_num)
		return (-1);
	len = print_str(str_num);
	free(str_num);
	return len;
}

int	print_pointer(void *ptr)
{
	unsigned long	address;
	char				*num;
	int				length;

	length = 0;
	address = (unsigned long)(ptr);
	num = convert_hex(address, 'x');
	if(!num)
		return (-1);
	length += print_str("0x");
	length += print_str(num);
	free(num);
	return length;
}