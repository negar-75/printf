#include "ft_printf.h"

static int	get_args(va_list *args, char format)
{
	if (format == 'c')
		return (print_char(va_arg(*args, int)));
	else if (format == 'd' || format == 'i')
		return (print_number(va_arg(*args, int)));
	else if (format == 's')
		return (print_str(va_arg(*args, char *)));
	else if (format == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (print_hex(va_arg(*args, unsigned int), format));
	else if (format == 'p')
		return (print_pointer(va_arg(*args, void *)));
	else if (format == '%')
		return (print_char('%'));
	return (0);
}

static int	handle_format(const char *format, va_list *args)
{
	int		len;
	int		i;
	ssize_t	ret;

	len = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ret = get_args(args, format[++i]);
			if (ret == -1)
				return (-1);
			len += ret;
		}
		else
		{
			ret = write(1, &format[i], 1);
			if (ret == -1)
				return (-1);
			len += ret;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	if (!format)
		return (-1);
	if (format_validation(format) > 0)
		return (-1);
	len = 0;
	va_start(args, format);
	len = handle_format(format, &args);
	va_end(args);
	return (len);
}
