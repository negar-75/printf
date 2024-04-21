NAME = libftprintf.a
LIBFT = libft.a
LIBFTDIR = ./libft
SRC = .
PRINTF_SRC = ft_printf.c ft_print_str.c ft_print_num.c functions.c ft_convert_unsigned.c ft_convert_hex.c
OBJS = $(PRINTF_SRC:.c=.o)
CC = cc 
AR = ar rcs
RM = rm -rf 
CFLAGS = -Wall -Wextra -Werror
CP = cp
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(CP) $(LIBFTDIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	
%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all