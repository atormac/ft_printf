NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c print_utils.c hex.c ft_write.c
OBJECTS = $(SOURCES:.c=.o)
LIBDIR= ./libft

all: $(NAME)

$(NAME): libft $(OBJECTS)
	ar -r $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	$(MAKE) -C $(LIBDIR)
	cp $(LIBDIR)/libft.a $(NAME)

clean:
	$(MAKE) -C $(LIBDIR) $@
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
