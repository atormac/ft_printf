# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 17:26:34 by atorma            #+#    #+#              #
#    Updated: 2024/04/30 17:26:36 by atorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_print_utils.c ft_hex.c ft_write.c
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
