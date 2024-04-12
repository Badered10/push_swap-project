# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:39:30 by baouragh          #+#    #+#              #
#    Updated: 2024/03/25 17:07:50 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C ../libft

SRCS = ft_dflags.c ft_cflags.c ft_printf.c \
		ft_isflag.c ft_uflags.c ft_sflags.c \
		ft_pflags.c ft_xsflags.c ft_tools1.c ft_tools2.c
		
BONUS_S = ft_dflags_bonus.c ft_cflags_bonus.c ft_printf_bonus.c \
		ft_isflag_bonus.c ft_uflags_bonus.c ft_sflags_bonus.c \
		ft_pflags_bonus.c ft_xsflags_bonus.c ft_tools1_bonus.c ft_tools2_bonus.c

LIBS = ../libft/libft.a

OBJS = $(SRCS:.c=.o)

BONUS_O = $(BONUS_S:.c=.o)

CP = cp ../libft/libft.a ../ft_printf/$(NAME)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@$(CP)
	@ar -rcs $(NAME) $(OBJS)
bonus: $(LIBS) $(BONUS_O)
	@$(CP)
	@ar -rcs $(NAME) $(BONUS_O)

$(LIBS):
	@$(MAKE)	
clean:
	@$(MAKE) clean
	@rm -f $(OBJS) $(BONUS_O)

fclean: clean
	@$(MAKE) fclean
	@rm -rf $(NAME)

re: fclean all
 
.PHONY: all clean fclean re
.SECONDARY: $(OBJS) $(BONUS_O)