# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 23:05:56 by baouragh          #+#    #+#              #
#    Updated: 2024/04/15 18:14:10 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

MAKE = make -C
MAKE = make -C
LIBS = ft_printf/libftprintf.a

SRSC_M = 	SRCS_M/sa.c SRCS_M/sb.c SRCS_M/ss.c\
			SRCS_M/parsing.c SRCS_M/pa.c SRCS_M/pb.c SRCS_M/ra.c SRCS_M/rb.c\
			SRCS_M/rr.c SRCS_M/rra.c SRCS_M/rrb.c SRCS_M/rrr.c SRCS_M/main.c\
			SRCS_M/utils1.c SRCS_M/utils2.c
SRCS_B = SRCS_B/quick_sort.c

OBJS_M = $(SRSC_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

NAME = push_swap
NAME_B = checker

all: $(NAME)
$(NAME): $(LIBS) $(OBJS_M)
	$(CC) $(CFLAGS) $(OBJS_M) $(LIBS) -o $(NAME)

bonus: $(NAME_B)
$(NAME_B): $(LIBS) $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIBS) -o $(NAME_B)

$(LIBS):
	$(MAKE) libft
	$(MAKE) libft bonus
	$(MAKE) ft_printf

clean:
	@rm -rf $(OBJS_B) $(OBJS_M)
	$(MAKE) ft_printf clean

fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	$(MAKE) ft_printf fclean

clear:
	@clear

.PHONY: clean clear
.SECONDARY: $(OBJS_B) $(OBJS_M)
