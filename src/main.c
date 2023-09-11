/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:31:56 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/21 19:31:56 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	ptr;
	char	*map_file;

	if (1 == map_valid(argc, argv, &ptr, &map_file))
		return (1);
	ptr.mlx_ptr = mlx_init();
	if (!ptr.mlx_ptr)
		return (write(2, "mlx Error\n", 10), 1);
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, ptr.len, ptr.hei, "so_long");
	if (!ptr.win_ptr)
		return (write(2, "win Error\n", 10), 1);
	player_sprites(&ptr);
	create_images(&ptr);
	find_player(&ptr);
	fill_window(&ptr);
	mlx_do_key_autorepeaton(ptr.mlx_ptr);
	mlx_hook(ptr.win_ptr, KeyPress, KeyPressMask, my_hook_test, &ptr);
	mlx_hook(ptr.win_ptr, DestroyNotify, 0L, destroy_window, &ptr);
	mlx_hook(ptr.win_ptr, FocusIn, FocusChangeMask, fill_window, &ptr);
	mlx_loop_hook(ptr.mlx_ptr, animations, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
