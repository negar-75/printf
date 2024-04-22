#include "ft_printf.h"

int	un_num_len(long unsigned int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int nbr)
{
    long unsigned num;
    int len;
    char *arr;

	num = nbr;
	len = un_num_len(num);
	arr = malloc((len + 1) * sizeof(char));
    if (!arr)
        return (NULL);
    arr[len] = '\0';
    if (num == 0)
    {
        arr[0] = '0';
        return (arr);
    }
    len--;
    while (num > 0)
    {
        arr[len] = num % 10 + '0';
        num = num / 10;
        len--;
    }
    return (arr);
}
