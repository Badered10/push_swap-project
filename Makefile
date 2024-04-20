# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 23:05:56 by baouragh          #+#    #+#              #
#    Updated: 2024/04/20 17:42:31 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
# -fsanitize=address -g3
MAKE = make -C
MAKE = make -C
LIBS = ft_printf/libftprintf.a

SRSC_M = 	SRCS_M/sa.c SRCS_M/sb.c SRCS_M/ss.c\
			SRCS_M/parsing.c SRCS_M/pa.c SRCS_M/pb.c SRCS_M/ra.c SRCS_M/rb.c\
			SRCS_M/rr.c SRCS_M/rra.c SRCS_M/rrb.c SRCS_M/rrr.c SRCS_M/main.c\
			SRCS_M/utils1.c SRCS_M/utils2.c SRCS_M/utils3.c

SRCS_B = 	SRCS_B/checker.c get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c SRCS_B/sa.c SRCS_B/sb.c SRCS_B/ss.c\
			SRCS_B/pa.c SRCS_B/pb.c SRCS_B/ra.c SRCS_B/rb.c SRCS_B/utils.c\
			SRCS_B/rr.c SRCS_B/rra.c SRCS_B/rrb.c SRCS_B/rrr.c SRCS_B/parsing.c 

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

re : fclean all

.PHONY: clean clear
.SECONDARY: $(OBJS_B) $(OBJS_M)
