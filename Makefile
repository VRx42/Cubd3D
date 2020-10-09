# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:35:27 by vronchin          #+#    #+#              #
#    Updated: 2020/05/12 21:12:09 by vronchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3d

FLAGS = -Wall -Werror -Wextra

LIBS = libmlx.a cube3dlib.a

EVENTS = ft_event.c \
		 ft_close_window.c \
		 ft_move_back.c \
		 ft_move_forward.c \
		 ft_move_left.c \
		 ft_move_right.c \
		 ft_move_cam.c

INIT = init_color.c \
	   init_data_map.c \
	   init_position.c \
	   init_resolution.c \
	   init_sprite.c \
	   init_texture.c \
	   init_var_default.c
	   
LIBFT =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memset.c \
		ft_memdel.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoinnplus.c \
		ft_strjoinplus.c \
		ft_strlen.c \
		ft_strlenn.c \
		ft_strncat.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnew.c \
		get_next_line.c

PARSING = ft_line_to_tab.c \
			   ft_parsing_data.c

RAYCASTING = ft_calcul_vec_dist.c \
			 ft_calcul_wall.c \
			 ft_raycasting_sprite.c \
			 ft_raycasting.c

UTILS = ft_display_error.c \
	   ft_exit_cube.c \
	   ft_put_image.c

CUBE3D_INC = cube3d.h libft/libft.h

ALL_SRCS = $(addprefix events/,$(EVENTS)) $(addprefix init/,$(INIT)) \
		   $(addprefix libft/,$(LIBFT)) $(addprefix parsing/,$(PARSING)) \
		   $(addprefix raycasting/,$(RAYCASTING)) $(addprefix utils/,$(UTILS))

OBJ = $(EVENTS:.c=.o) $(INIT:.c=.o) $(LIBFT:.c=.o) $(PARSING:.c=.o) \
		$(RAYCASTING:.c=.o) $(UTILS:.c=.o)
.PHONY : clean fclean re all
.SILENT : clean fclean re all cube3dlib $(NAME)
all: $(NAME)

$(NAME) : cube3dlib $(ALL_SRCS) $(CUBE3D_INC)
		echo "\033[1;33mCUBE3D compiling...\033[0m"
		gcc -o cube3d cube3d.c cube3dlib.a libmlx.a -Wall -Werror -Wextra -lXext -lX11 -lm -lbsd
		echo "\033[32mCUBE3D compilation over.\033[0m"

cube3dlib :
	gcc $(FLAGS) -c $(ALL_SRCS) -I./
	ar rc cube3dlib.a $(OBJ)
	ranlib cube3dlib.a
	rm -f $(OBJ)

clean :
	echo "\033[1;33mCleaning CUBE3D...\033[0m"
	rm -f $(NAME)
	rm -f cube3dlib.a
	echo "\033[0;35m$(NAME) executable removed.\033[0m"

fclean: clean
		echo "\033[0;35m$(NAME) executable removed.\033[0m"
re: fclean all
