/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:24:36 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/12 20:27:23 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "../../../../usr/X11/include/X11/X.h"
# include <time.h>
# include "libft/ft_printf.h"

// # include <fcntl.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
// # include <X11/keysymdef.h>

# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 400

// typedef struct s_data_image
// {
	// void	*img;
	// char	*addr;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
// }				t_data_img;

typedef struct s_player_images
{
	void					*frame;
	struct s_player_images	*next;
}				t_pimg;

typedef struct s_img
{
	void	*wall;
	t_pimg	*player;
	void	*end;
	void	*path;
	void	*c;
	void	*p_r;
	void	*p_l;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		p_x;
	int		p_y;
	int		c_count;
	t_img	img;
	t_pimg	*start_img;
	int		hei;
	int		len;
	int		move_count;
}				t_data;

int		map_valid(int argc, char **argv, t_data *data_ptr, char **map_file);
char	**validate_the_map(char **map_file, t_data *data_ptr);
char	**create_the_map(int number_of_lines, char **map_file);
int		free_map(char **map_array);
void	print_map(char **map_array);
int		side_walls(char **map_array, int line_count, int char_count);
int		test_outside_walls(char **map_array);
size_t	linelen(const char *s);
int		test_for_dup_char(char **map_array, char p_or_e);
char	**copy_map(char **map_array);
int		iterate_the_map(char **map_file, int *collectible_count);
int		check_line_length(size_t line_lenght, char **map_array, int i);
int		find_valid_path(char **map_array, int expectet_collect, int exit_found);
void	find_start(char **map_copy, int *line_count, int *char_count);
int		flood_the_map(char **map_copy, int line_start, int char_start, int *c);
int		is_exit_ok(char **map_copy, int line_start, int char_start, int *exit);
int		go_right(t_data *ptr);
int		go_left(t_data *data_ptr);
int		go_up(t_data *data_ptr);
int		go_down(t_data *data_ptr);
int		fill_window(t_data *data_ptr);
int		destroy_window(t_data *data_ptr);
void	place_image(void *image, t_data	*data_ptr, int x, int y);
void	delete_images(t_data *ptr);
void	create_images(t_data *ptr);
void	next_frame(t_data *data_ptr);
void	add_back(t_pimg **lst, t_pimg *new_last);
void	player_sprites(t_data *ptr);
void	player_sprites_2(t_data *ptr);
void	find_player(t_data *data_ptr);
int		free_frames(t_data	*data_ptr);
void	map_size(t_data *data_ptr);
int		my_hook_test(int keycode, t_data *data_ptr);
int		animations(t_data *data_ptr);
t_pimg	*new_frame(void *content);
t_pimg	*find_last(t_pimg **lst);
int		free_map_2(char **map_array, int lines);

// void	place_wall(t_data *data_ptr, int x, int y);
// void	place_path(t_data *data_ptr, int x, int y);
// void	place_player(t_data *data_ptr, int x, int y);
// void	place_end(t_data *data_ptr, int x, int y);
// void	place_collect(t_data *data_ptr, int x, int y);

#endif