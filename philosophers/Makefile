# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 22:13:53 by misikogl          #+#    #+#              #
#    Updated: 2022/12/21 06:08:06 by misikogl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

cc		= gcc

SRCS = $(wildcard srcs/*.c)

OBJS	= $(SRCS:.c=.o)

RM = rm -rf

FLAGS	= -Wall -Wextra -Werror	#-fsanitize=thread -g


TFLAG = -pthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(TFLAG) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)
	
fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re