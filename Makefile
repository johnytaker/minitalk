# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/01/21 18:30:23 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
LIBFT = make -C ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes/minitalk.h
RM = @rm -f
$(NAME)	:	$(SERVER) $(CLIENT)
server:	$(OBJ_SERVER)
			$(LIBFT)
			$(CC) $(CFLAGS) $(OBJ_SERVER) libft/libft.a -o $(SERVER) -I $(HEADER)
client:	$(OBJ_CLIENT)
			$(LIBFT)
			$(CC) $(CFLAGS) $(OBJ_CLIENT) libft/libft.a -o $(CLIENT) -I $(HEADER)
bonus: all
clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	cd ./libft && make clean
fclean:	clean
		$(RM) $(NAME)
		cd ./libft && make fclean
all:	$(NAME)
re:		fclean all
.PHONY:	all clean fclean re bonus

