#include "ft_printf.h"

int main()
{
	
    printf("my%d\n",ft_printf(" %p %p ", 0, 0));
	printf("lib%d\n",printf(" %p %p ", 0, 0));

    return 0;
}