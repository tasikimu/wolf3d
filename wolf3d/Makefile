# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/28 14:44:59 by tasikimu          #+#    #+#              #
#    Updated: 2018/09/07 14:53:45 by tasikimu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d 

SRCS =  read.c draw.c ft_atoi.c control.c \
		ft_memalloc.c ft_strcat.c ft_strcpy.c \
		ft_strjoin.c ft_strsplittoint.c ft_strsub.c \
		get_next_line.c raycast.c ft_strlen.c \
		main.c

OBJS =  controls.o draw.o ft_atoi.o control.o \
		ft_memalloc.o ft_strcat.o ft_strcpy.o \
		ft_strjoin.o ft_strsplittoint.o ft_strsub.o \
		get_next_line.o raycast.o ft_strlen.o \
		main.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
		gcc $(CFLAGS) $(SRCS) -o $(NAME) $(FRAMEWORK)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
