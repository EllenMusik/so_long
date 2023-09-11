/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:57:54 by ellensteine       #+#    #+#             */
/*   Updated: 2023/08/12 20:39:56 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	go_right(t_data *ptr)
{
	if (ptr->map[ptr->p_y][ptr->p_x + 1] == '1')
		return (0);
	ptr->move_count++;
	ft_printf("moves: %i\n", ptr->move_count);
	if (ptr->map[ptr->p_y][ptr->p_x + 1] == 'C')
		ptr->c_count -= 1;
	if (ptr->map[ptr->p_y][ptr->p_x + 1] == 'E')
	{
		if (ptr->c_count == 0)
			return (destroy_window(ptr), 0);
		ptr->map[ptr->p_y][ptr->p_x + 1] = 'e';
	}
	else
		ptr->map[ptr->p_y][ptr->p_x + 1] = 'P';
	if (ptr->map[ptr->p_y][ptr->p_x] == 'e')
	{
		ptr->map[ptr->p_y][ptr->p_x] = 'E';
		place_image(ptr->img.end, ptr, ptr->p_x * 100, ptr->p_y * 100);
	}
	else
	{
		ptr->map[ptr->p_y][ptr->p_x] = '0';
		place_image(ptr->img.path, ptr, ptr->p_x * 100, ptr->p_y * 100);
	}
	return (0);
}

int	go_left(t_data *ptr)
{
	if (ptr->map[ptr->p_y][ptr->p_x - 1] == '1')
		return (0);
	ptr->move_count++;
	ft_printf("moves: %i\n", ptr->move_count);
	if (ptr->map[ptr->p_y][ptr->p_x - 1] == 'C')
		ptr->c_count -= 1;
	if (ptr->map[ptr->p_y][ptr->p_x - 1] == 'E')
	{
		ptr->map[ptr->p_y][ptr->p_x - 1] = 'e';
		if (ptr->c_count == 0)
			return (destroy_window(ptr), 0);
	}
	else
		ptr->map[ptr->p_y][ptr->p_x - 1] = 'P';
	if (ptr->map[ptr->p_y][ptr->p_x] == 'e')
	{
		ptr->map[ptr->p_y][ptr->p_x] = 'E';
		place_image(ptr->img.end, ptr, ptr->p_x * 100, ptr->p_y * 100);
	}
	else
	{
		ptr->map[ptr->p_y][ptr->p_x] = '0';
		place_image(ptr->img.path, ptr, ptr->p_x * 100, ptr->p_y * 100);
	}
	return (0);
}

int	go_down(t_data *ptr)
{
	if (ptr->map[ptr->p_y + 1][ptr->p_x] == '1')
		return (0);
	ptr->move_count++;
	ft_printf("moves: %i\n", ptr->move_count);
	if (ptr->map[ptr->p_y + 1][ptr->p_x] == 'C')
		ptr->c_count -= 1;
	if (ptr->map[ptr->p_y + 1][ptr->p_x] == 'E')
	{
		ptr->map[ptr->p_y + 1][ptr->p_x] = 'e';
		if (ptr->c_count == 0)
			return (destroy_window(ptr), 0);
	}
	else
		ptr->map[ptr->p_y + 1][ptr->p_x] = 'P';
	if (ptr->map[ptr->p_y][ptr->p_x] == 'e')
	{
		ptr->map[ptr->p_y][ptr->p_x] = 'E';
		place_image(ptr->img.end, ptr, ptr->p_x * 100, ptr->p_y * 100);
	}
	else
	{
		ptr->map[ptr->p_y][ptr->p_x] = '0';
		place_image(ptr->img.path, ptr, ptr->p_x * 100, ptr->p_y * 100);
	}
	return (0);
}

int	go_up(t_data *ptr)
{
	if (ptr->map[ptr->p_y - 1][ptr->p_x] == '1')
		return (0);
	ptr->move_count++;
	ft_printf("moves: %i\n", ptr->move_count);
	if (ptr->map[ptr->p_y - 1][ptr->p_x] == 'C')
		ptr->c_count -= 1;
	if (ptr->map[ptr->p_y - 1][ptr->p_x] == 'E')
	{
		ptr->map[ptr->p_y - 1][ptr->p_x] = 'e';
		if (ptr->c_count == 0)
			return (destroy_window(ptr), 0);
	}
	else
		ptr->map[ptr->p_y - 1][ptr->p_x] = 'P';
	if (ptr->map[ptr->p_y][ptr->p_x] == 'e')
	{
		ptr->map[ptr->p_y][ptr->p_x] = 'E';
		place_image(ptr->img.end, ptr, ptr->p_x * 100, ptr->p_y * 100);
	}
	else
	{
		ptr->map[ptr->p_y][ptr->p_x] = '0';
		place_image(ptr->img.path, ptr, ptr->p_x * 100, ptr->p_y * 100);
	}
	return (0);
}
