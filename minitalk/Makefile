# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smia <smia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 06:21:52 by smia              #+#    #+#              #
#    Updated: 2022/01/17 19:05:30 by smia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INC = minitalk.h
INC_BONUS = minitalk_bonus.h

CFLAGS = -Wall -Wextra -Werror


all : server client

bonus: server_bonus client_bonus

server: server.c minitalk_utils.c $(INC)
	cc $(CFLAGS) server.c minitalk_utils.c -o server

client: client.c minitalk_utils.c $(INC)
	cc $(CFLAGS) client.c minitalk_utils.c -o client
	
server_bonus: server_bonus.c minitalk_utils.c $(INC_BONUS)
	cc $(CFLAGS) server_bonus.c minitalk_utils.c -o server_bonus

client_bonus: client_bonus.c minitalk_utils.c $(INC_BONUS)
	cc $(CFLAGS)  client_bonus.c minitalk_utils.c -o client_bonus

clean:
	
fclean : clean
	rm -rf server server_bonus client client_bonus

re : fclean all