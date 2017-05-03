# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 18:07:52 by lfabbro           #+#    #+#              #
#    Updated: 2016/11/11 17:39:30 by lfabbro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lfabbro.filler
SRC_NAME = main.c ft_get.c ft_place.c ft_tools.c ft_graphic.c ft_sdl.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAMES = -lft

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/ ./libft/includes/ ./libft/libft 
#./SDL2/include
LIB_PATH = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

## SOURCES ##
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))


## INCLUDES ##
INC = $(addprefix -I,$(INC_PATH))
INC += -I/usr/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT


## LIBRARIES ##
LIB_LINK = $(addprefix -L,$(LIB_PATH))
LIB = $(LIB_NAMES)  #$(addprefix -l , $(LIB_NAMES))
SDL = -L/usr/lib -lSDL2 -lpthread

## FRAMEWORKS ##
#FRAMEW = -framework OpenGL

.PHONY: all clean fclean re norme

## RULES ##
all:
	@make -C $(LIB_PATH)
	@echo -e "\033[44m\033[32mMaking $(NAME)\033[0m\033[0m"
	@make $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INC) $(LIB_LINK) $(SRC) $(LIB) $(SDL) -o $(NAME) $(FRAMEW)

sdl:
	@echo -e "\033[44m\033[32mMaking SDL2\033[0m\033[0m"
	./scripts/build_sdl.sh

sdlclean:
	@echo -e "\033[44m\033[31mRemoving SDL2\033[0m\033[0m"
	@/bin/rm -rfv libsdl

clean : libclean
	@echo -e "\033[44m\033[31mRemoving $(NAME) objects\033[0m\033[0m"
	@/bin/rm -fv $(OBJ)

fclean : libfclean clean
	@echo -e "\033[44m\033[31mRemoving $(NAME)\033[0m\033[0m"
	@/bin/rm -fv $(NAME)

libre :
	@make -C $(LIB_PATH) re

libclean :
	@make -C $(LIB_PATH) clean

libfclean :
	@make -C $(LIB_PATH) fclean

re : fclean all

norme :
	norminette $(SRC)
	norminette $(INC_PATH)*
