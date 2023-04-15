# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andreys <andreys@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 15:59:38 by nnelson           #+#    #+#              #
#    Updated: 2023/04/15 15:16:42 by andreys          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = fractol

# FILES = main.c validate_fractal.c draw_fractal.c\
# 		mandelbrot.c julia.c burningship.c\
# 		color_schemes.c get_color.c\
# 		libft_utils.c libft_utils2.c\
# 		mouse_hooks.c keyboard_hooks.c

# HDRS  = fractol.h keys.h
		
# OBJS = 	$(FILES:.c=.o)

# CC = gcc
# FLAGS = -Wall -Wextra -Werror -g

# RM = rm -f

# .PHONY: all clean fclean re

# %.o:	%.c ${HDRS}
# 			${CC} ${FLAGS} -I mlx -c $< -o $@

# ${NAME}: ${OBJS}
# 			${CC} ${FLAGS} ${OBJS} -l mlx -framework OpenGL -framework AppKit -o ${NAME}

# all: ${NAME}

# clean:
# 	${RM} ${OBJS}

# fclean: clean
# 	${RM} ${OBJS} ${NAME}
	
# re: fclean all

NAME	= fractol

# directories
SRCDIR	= ./src
INCDIR	= ./includes
OBJDIR	= ./obj

# src / obj files
SRC		= main.c \
		  burningship.c \
		  color_schemes.c \
		  draw_fractal.c \
		  get_color.c \
		  julia.c \
		  keyboard_hooks.c \
		  libft_utils.c \
		  libft_utils2.c \
		  mandelbrot.c \
		  mouse_hooks.c \
		  validate_fractal.c \

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g


# mlx library
	MLX		= ./mlx/
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

all: obj $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/fractals

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(INCDIR) -o $@ -c $<

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all