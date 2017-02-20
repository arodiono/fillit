# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodiono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/03 20:43:12 by arodiono          #+#    #+#              #
#    Updated: 2017/01/03 20:43:15 by arodiono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra
SRC = main.c map.c print_fig.c read_file.c read_figure.c ft_putstr.c \
		ft_memset.c ft_putchar.c
		OSRC =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)

	gcc $(FLAGS) -o $(NAME) $(OSRC)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
