# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/01/23 12:17:20 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
NAME = $(SERVER) $(CLIENT)
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
LIBFT_HEADER = ./libft/libft.h
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes/minitalk.h
RM = rm -f

NAME:	$(SERVER) $(CLIENT)

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(LIBFT):	$(LIBFT_HEADER)
		make -C libft

server:	$(LIBFT) $(OBJ_SERVER) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

client:	$(LIBFT) $(OBJ_CLIENT) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

bonus: all

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
		make clean -C libft

fclean:	clean
		$(RM) $(NAME)
		make fclean -C libft

re:		fclean all

.PHONY:	all clean fclean re bonus

