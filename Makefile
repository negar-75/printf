NAME = libftprintf.a
LIBFT = libft.a
LIBFTDIR = ./Libft
SRC = .
PRINTF_SRC = ft_printf.c ft_print_hex.c ft_pt_un.c functions.c
OBJS = $(PRINTF_SRC:.c=.o)
CC = cc 
AR = ar rcs
RM = rm -rf 
CFLAGS = -Wall -Wextra -Werror
CP = cp
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CP) $(LIBFTDIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all