/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:30:26 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/12 20:47:11 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_sprites(t_data *ptr)
{
	int		x;
	int		y;
	t_pimg	*temp;

	ptr->start_img = NULL;
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/1.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/2.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/3.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/4.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/5.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/6.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/7.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/8.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	player_sprites_2(ptr);
}

void	player_sprites_2(t_data *ptr)
{
	int		x;
	int		y;
	t_pimg	*temp;

	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/9.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/10.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/11.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/12.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
	temp = new_frame(mlx_xpm_file_to_image(ptr->mlx_ptr, "spr/13.xpm", &x, &y));
	add_back(&ptr->start_img, temp);
}

void	add_back(t_pimg **lst, t_pimg *new_last)
{
	t_pimg	*old_last;

	if (*lst)
	{
		old_last = find_last(lst);
		old_last->next = new_last;
		new_last->next = *lst;
	}
	if (!*lst)
	{
		*lst = new_last;
		new_last->next = new_last;
	}
}

t_pimg	*find_last(t_pimg **lst)
{
	t_pimg	*first_node;
	t_pimg	*node;

	if (!*lst)
		return (NULL);
	first_node = *lst;
	node = *lst;
	node = node->next;
	while (node && node->next != first_node)
	{
		node = node->next;
	}
	return (node);
}

t_pimg	*new_frame(void *content)
{
	t_pimg	*frame;

	frame = ft_calloc(1, sizeof(t_pimg));
	frame->frame = content;
	frame->next = NULL;
	return (frame);
}
