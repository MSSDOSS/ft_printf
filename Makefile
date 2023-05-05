# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 16:12:59 by hel-haia          #+#    #+#              #
#    Updated: 2023/05/05 18:06:51 by hel-haia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c \
			tools.c \
			hex.c \

OBJS	= $(SRCS:%.c=%.o)

INCS	= ft_printf.h

FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c $(INCS)
		cc $(FLAGS) -c $<

$(NAME):$(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
