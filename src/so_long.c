/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:33:42 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/12 20:41:08 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	my_hook_test(int keycode, t_data *data_ptr)
{
	if (keycode == 65307)
		destroy_window(data_ptr);
	if (keycode == 'w' || keycode == 65362)
		go_up(data_ptr);
	if (keycode == 's' || keycode == 65364)
		go_down(data_ptr);
	if (keycode == 'd' || keycode == 65363)
		go_right(data_ptr);
	if (keycode == 'a' || keycode == 65361)
		go_left(data_ptr);
	find_player(data_ptr);
	return (0);
}

int	fill_window(t_data *ptr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (ptr->map[y])
	{
		while (ptr->map[y][x] && ptr->map[y][x] != '\n')
		{
			if (ptr->map[y][x] == '1')
				place_image(ptr->img.wall, ptr, x * 100, y * 100);
			if (ptr->map[y][x] == '0')
				place_image(ptr->img.path, ptr, x * 100, y * 100);
			if (ptr->map[y][x] == 'C')
				place_image(ptr->img.c, ptr, x * 100, y * 100);
			if (ptr->map[y][x] == 'E')
				place_image(ptr->img.end, ptr, x * 100, y * 100);
			if (ptr->map[y][x] == 'P')
				place_image(ptr->img.player->frame, ptr, x * 100, y * 100);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	animations(t_data *data_ptr)
{
	clock_t					timer;
	static unsigned long	iterations;

	if (!iterations)
		iterations = 0;
	timer = clock() / 70000;
	if (timer > iterations)
	{
		iterations++;
		next_frame(data_ptr);
	}
	return (0);
}

void	next_frame(t_data *ptr)
{
	ptr->img.player = ptr->img.player->next;
	find_player(ptr);
	place_image(ptr->img.player->frame, ptr, ptr->p_x * 100, ptr->p_y * 100);
}

int	map_valid(int argc, char **argv, t_data *data_ptr, char **map_file)
{
	if (argc != 2)
		return (write(2, "please put only the map file as argument.\n", 42), 1);
	*map_file = argv[1];
	data_ptr->map = validate_the_map(map_file, data_ptr);
	if (!data_ptr->map)
		return (1);
	map_size(data_ptr);
	if (data_ptr->hei > 1400 || data_ptr->len > 2600)
		return (write(1, "map too big\n", 12), 1);
	find_player(data_ptr);
	data_ptr->move_count = 0;
	return (0);
}
