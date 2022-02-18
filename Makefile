# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moguy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 02:35:52 by moguy             #+#    #+#              #
#    Updated: 2022/02/18 13:59:34 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF = \033[0m
GRA = \033[1m
SOU = \033[4m
BLI = \033[5m
BLA = \033[30m
RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
PUR = \033[35m
CYA = \033[36m
WHI = \033[37m
ORG = \033[1;31m

CC = gcc

MAKEFLAGS += -s

CFLAGS = -Wall -Werror -Wextra

NAME = fract

NAME2 = fractol

SRCS_NAME2 = ft_error2.c \
			 main2.c

SRCS_NAME = fract_ol.c \
			ft_deal.c \
			ft_deal3.c \
			threads.c \
			ft_deal2.c \
			ft_error.c \
			fill_color.c \
			ft_init.c \
			main.c

SRCS_PATH2 = srcs2/

SRCS_PATH = srcs/

MLX_NAME = libmlx.a

MLX_DIR = mlx_opengl/

HDR_NAME = fract_ol.h

HDR_PATH = includes/

LIB_NAME = libft.a

LIB_PATH = libft/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

SRCS2 = $(addprefix $(SRCS_PATH2), $(SRCS_NAME2))

MLX = $(addprefix $(MLX_DIR), $(MLX_NAME))

HDR = $(addprefix $(HDR_PATH), $(HDR_NAME))

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

OBJ = $(SRCS:.c=.o)

OBJ2 = $(SRCS2:.c=.o)

.PHONY: all clean fclean re

all : $(NAME) $(NAME2)

$(NAME2) : $(LIB) $(OBJ2) $(HDR)
			@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) -framework OpenGL -framework \
				Appkit $(LIB) $(MLX)
			@echo "$(ORG)Make fractol$(DEF) : $(GRE)Done!$(DEF)"

$(NAME) : $(LIB) $(OBJ) $(HDR)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -framework OpenGL -framework \
				AppKit -lpthread $(LIB) $(MLX)
			@echo "$(ORG)Make fract$(DEF) : $(GRE)Done!$(DEF)"

$(LIB) : FORCE
			@make -C $(LIB_PATH)

%.o : %.c $(HDR)
			@$(CC) $(CFLAGS) -c $< -o $@ -I includes/ -I mlx_opengl

clean : $(SRCS)
			@make -C libft/ clean
			@rm -rf $(OBJ) $(OBJ2)
			@echo "$(ORG)fractol clean$(DEF) : $(GRE)Done!$(DEF)"

fclean : clean
			@make -C libft/ fclean
			@rm -rf $(NAME) $(NAME2)
			@echo "$(ORG)fractol fclean$(DEF) : $(GRE)Done!$(DEF)"

FORCE:

re : fclean all
