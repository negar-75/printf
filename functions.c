#include "ft_printf.h"

int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int print_number(int num)
{
    char *str_num;
    int len;

    str_num = ft_itoa(num);
    ft_putstr_fd(str_num,1);
    len = ft_strlen(str_num);
    free(str_num);
    return len;
}
int print_str(char *s)
{
    if (!s)
    {
      write(1, "(null)", 6);
      return (6);
    }
        
    ft_putstr_fd(s, 1);
    return ((int)ft_strlen(s));
}
int print_unsigned(unsigned num) 
{
    char *str_num;
    int len; 

    str_num = ft_utoa(num);
    ft_putstr_fd(str_num,1);
    len = ft_strlen(str_num);
    free(str_num);
    return len;
}
 
int print_hex(unsigned int num,char format)
{
    char *str_num;
    int len;

    str_num = convert_hex(num,format);
    ft_putstr_fd(str_num,1);
    len = ft_strlen(str_num);
    free(str_num);
    return len;
}
int print_pointer (void *ptr)
{
   unsigned long  address;
   char *num;
   int length;
   
   address = (unsigned long)(ptr);
   num = convert_hex(address,'x');
   ft_putstr_fd("0x", 1);
   ft_putstr_fd(num, 1);
   length = ft_strlen(num) + 2;
   free(num);
   return length;
}