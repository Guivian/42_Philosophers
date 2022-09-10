# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:59:09 by lbarbosa          #+#    #+#              #
#    Updated: 2022/09/08 18:32:11 by lbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror -g -lpthread -o

HEADERS = philosophers.h

C_FILES = main.c srcs/validate_args.c srcs/convert_args.c 

all:$(NAME)

$(NAME):
	@gcc $(FLAGS) $(NAME) $(HEADERS) $(C_FILES)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
