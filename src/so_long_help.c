/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:33:35 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/21 19:33:41 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_images(t_data *ptr)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	ptr->img.wall = mlx_xpm_file_to_image(ptr->mlx_ptr, "imgs/1.xpm", &x, &y);
	ptr->img.path = mlx_xpm_file_to_image(ptr->mlx_ptr, "imgs/0.xpm", &x, &y);
	ptr->img.p_l = mlx_xpm_file_to_image(ptr->mlx_ptr, "imgs/PP.xpm", &x, &y);
	ptr->img.p_r = mlx_xpm_file_to_image(ptr->mlx_ptr, "imgs/P.xpm", &x, &y);
	ptr->img.end = mlx_xpm_file_to_image(ptr->mlx_ptr, "imgs/jiji.xpm", &x, &y);
	ptr->img.c = mlx_xpm_file_to_image(ptr->mlx_ptr, "imgs/C.xpm", &x, &y);
	ptr->img.player = ptr->start_img;
}

void	map_size(t_data *data_ptr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data_ptr->map[y])
	{
		while (data_ptr->map[y][x] && data_ptr->map[y][x] != '\n')
			x++;
		y++;
		data_ptr->len = x * 100;
		x = 0;
	}
	data_ptr->hei = y * 100;
}

void	find_player(t_data *data_ptr)
{
	int		x;
	int		y;
	char	**map;

	map = data_ptr->map;
	x = 0;
	y = 0;
	while (map[y] && map[y][x] != 'P')
	{
		while (map[y][x] && map[y][x] != '\n' && map[y][x] != 'P'
				&& map[y][x] != 'e')
		{
			x++;
		}
		if (map[y][x] == 'P' || map[y][x] == 'e')
			break ;
		y++;
		x = 0;
	}
	data_ptr->p_x = x;
	data_ptr->p_y = y;
}

void	place_image(void *image, t_data	*ptr, int x, int y)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, image, x, y);
}
