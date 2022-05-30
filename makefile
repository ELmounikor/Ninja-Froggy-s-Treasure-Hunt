# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 16:48:53 by mel-kora          #+#    #+#              #
#    Updated: 2022/05/30 20:04:19 by mel-kora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c\
				map_checker.c\
				counters.c\
				cleaners.c\
				player_mover.c\
				monster_mover.c\
				window.c\
				game.c\
				Libft/ft_putendl_fd.c\
				Libft/ft_split.c\
				Libft/ft_strchr.c\
				Libft/ft_strlen.c\
				Libft/ft_strnstr.c\
				Libft/ft_strtrim.c\
				Libft/ft_itoa.c\
				Libft/ft_error.c


OBJS		=	${SRCS:.c=.o}

MAP_SRCS		=	map_generator.c\
				Libft/ft_putendl_fd.c\
				Libft/ft_strlen.c\
				Libft/ft_atoi.c\
				Libft/ft_error.c


MAP_OBJS		=	${MAP_SRCS:.c=.o}

MAP			=	map.ber

NAME		=	"ELmounikor Ninja Froggy's treasure hunt.exe"

MAP_NAME	=	map_maker

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Werror -Wextra #-g -fsanitize=address

.c.o:
			${CC} ${CFLAGS} -Imlx -c $< -o $@
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o  ${NAME}
			./${NAME} ${MAP}
			
		
all:		${NAME}

${MAP_NAME}:	${MAP_OBJS}
				${CC} ${CFLAGS} ${MAP_OBJS} -o ${MAP_NAME}
				#./${MAP_NAME} "10CEMP" 1337 7331

map:		${MAP_NAME}

clean:
			${RM} ${OBJS} ${MAP_OBJS}

fclean:		clean
			${RM} ${NAME} ${MAP_NAME}

re:			fclean all

.PHONY:		all clean fclean re
