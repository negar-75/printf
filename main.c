#include "ft_printf.h"
int main()
{
	
    printf("my%d\n",ft_printf("\001\002\007\v\010\f\r\n"));
	printf("lib%d\n",printf("\001\002\007\v\010\f\r\n"));

    return 0;
}