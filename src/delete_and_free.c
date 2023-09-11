/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:15:07 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/21 19:15:38 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destroy_window(t_data *data_ptr)
{
	free_map(data_ptr->map);
	delete_images(data_ptr);
	free_frames(data_ptr);
	mlx_loop_end(data_ptr->mlx_ptr);
	mlx_destroy_window(data_ptr->mlx_ptr, data_ptr->win_ptr);
	mlx_destroy_display(data_ptr->mlx_ptr);
	free(data_ptr->mlx_ptr);
	exit(0);
}

int	free_frames(t_data	*data_ptr)
{
	t_pimg	*start;
	t_pimg	*adresse;
	t_pimg	*temporary;

	if (data_ptr && data_ptr->start_img != NULL)
	{
		start = data_ptr->start_img;
		adresse = start->next;
		while (adresse && adresse != start)
		{
			mlx_destroy_image(data_ptr->mlx_ptr, adresse->frame);
			temporary = adresse->next;
			free(adresse);
			adresse = temporary;
		}
		mlx_destroy_image(data_ptr->mlx_ptr, start->frame);
		free(start);
	}
	return (0);
}

void	delete_images(t_data *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img.c);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img.end);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img.p_l);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img.p_r);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img.path);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img.wall);
}

int	free_map(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
	return (0);
}
