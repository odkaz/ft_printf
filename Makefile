NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := ar -rc
SRCS := ft_printf.c print_c.c print_int.c print_p.c \
		print_s.c print_u.c print_x.c
OBJS := $(SRCS:.c=.o)
SUBDIRS = ./libft \

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: $(SUBDIRS)
	rm -f $(OBJS)

fclean: $(SUBDIRS) clean
	rm -f $(NAME)

re: $(SUBDIRS) fclean all

$(SUBDIRS) : FORCE
	make -C $@ $(MAKECMDGOALS)

FORCE:

.PHONY: all clean fclean re
