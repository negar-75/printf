#include "ft_printf.h"

int	format_validation(const char* format)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (format[++i])
	{
		if(format[i] == '%')
		{
			i++;
			if (!(format[i] == '%' || format[i] == 's' || format[i] == 'c'
				|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X' || format[i] == 'p'))
				{
					count++;
				}
		}
	}
	return (count);
}
