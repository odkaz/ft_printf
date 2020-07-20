NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := ar -rc
SRCS := ft_printf.c print_c.c print_int.c print_p.c \
		print_s.c print_u.c print_x.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
