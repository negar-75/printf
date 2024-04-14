#include "ft_printf.h"

static int get_args(va_list *args, char format)
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
    return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int len;

    len = 0;
    i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {

            len += get_args(&args, format[i + 1]);
            i++;
        }
        else
        {
            write(1, &format[i], 1);
            len++;
        }
        i++;
    }
    va_end(args);
    return len;
}