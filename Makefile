NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
DEBUG = -fsanitize=address
HEADER = so_long.h
RM = rm -rf
NAME = so_long
MLX_FLAGS = -L/usr/X11/lib -lX11 -lXext -lm

SRC_DIR	=	./src
OBJ_DIR	=	./obj

LIBFT	=	libft/libft.a

PRINTF	=	ft_printf/libftprintf.a

MLX		=	mlx/libmlx.a

FILES	=	so_long \
 			map_input \
 			map_input_check \
 			find_map_path \
 			movement \
 			animation \
 			delete_and_free \
 			so_long_help \
 			main \

SRC		=	$(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJ		=	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))


all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(MAKE) bonus -C libft
	$(CC) $(DEBUG) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)
#cp ./get_next_line/get_next_line_utils.o .
#$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a libmlx.a -lm -framework OpenGL -framework AppKit

$(MLX):
	make -C mlx >/dev/null 2>&1

#$(O_FILES):
#	cc $(CFLAGS) -I /usr/X11/include -c $(FILES) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -I /usr/X11/include -o $@ -c $<

clean:
	$(MAKE) clean -C libft
	make clean -C mlx
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)
	
re: fclean all

run:
	./$(NAME) test_map.ber

.PHONY: all clean fclean re