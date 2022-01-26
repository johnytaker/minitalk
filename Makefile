# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/01/26 16:22:07 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
NAME = minitalk
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
SRC_SERVER_B = server_bonus.c
SRC_CLIENT_B = client_bonus.c
OBJ_SERVER_B = $(SRC_SERVER_B:.c=.o)
OBJ_CLIENT_B = $(SRC_CLIENT_B:.c=.o)
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes/minitalk.h
RM = rm -f

$(NAME):	lib server client

all:	$(NAME)

%.o: %.c $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	make -C libft

server:	$(OBJ_SERVER)
			$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

client:	$(OBJ_CLIENT)
			$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

bonus:
	make "OBJ_SERVER=$(OBJ_SERVER_B)" "OBJ_CLIENT=$(OBJ_CLIENT_B)" all

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)
		make clean -C libft

fclean:	clean
		$(RM) $(SERVER) $(CLIENT)
		make fclean -C libft

re:	fclean all

.PHONY:	all clean fclean re bonus

