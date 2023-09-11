/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:18:33 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/21 16:46:12 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_valid_path(char **map_array, int expectet_collect, int exit_found)
{
	char	**map_copy;
	int		line_start;
	int		char_start;
	int		collect;

	line_start = 0;
	char_start = 0;
	collect = 0;
	map_copy = copy_map(map_array);
	find_start(map_copy, &line_start, &char_start);
	flood_the_map(map_copy, line_start, char_start, &collect);
	if (collect != expectet_collect)
	{
		write(2, "not all collectibles are reachable.\n", 36);
		return (free_map(map_copy), 1);
	}
	is_exit_ok(map_copy, line_start, char_start, &exit_found);
	if (0 == exit_found)
	{
		write(2, "exit could not be reached\n", 26);
		return (free_map(map_copy), 1);
	}
	return (free_map(map_copy), 0);
}

char	**copy_map(char **map_array)
{
	int		i;
	char	**map_copy;

	i = 0;
	while (map_array[i])
		i++;
	map_copy = malloc(sizeof(char *) * (i + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map_array[i])
	{
		map_copy[i] = malloc(sizeof(char) * strlen(map_array[i]) + 1);
		ft_strlcpy(map_copy[i], map_array[i], strlen(map_array[i]) + 1);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	find_start(char **map_copy, int *line_count, int *char_count)
{
	while (map_copy[*line_count])
	{
		while (map_copy[*line_count][*char_count])
		{
			if (map_copy[*line_count][*char_count] == 'P')
				break ;
			char_count[0]++;
		}
		if (map_copy[*line_count][*char_count] == 'P')
			break ;
		char_count[0] = 0;
		line_count[0]++;
	}
}

int	flood_the_map(char **map_copy, int line_start, int char_start, int *c)
{
	if ('C' == map_copy[line_start][char_start])
		c[0]++;
	if ('E' != map_copy[line_start][char_start])
		map_copy[line_start][char_start] = 'X';
	if (map_copy[line_start][char_start + 1] == '0'
	|| map_copy[line_start][char_start + 1] == 'C' 
	|| map_copy[line_start][char_start + 1] == 'E')
		flood_the_map(map_copy, line_start, char_start + 1, c);
	if (map_copy[line_start][char_start - 1] == '0'
	|| map_copy[line_start][char_start - 1] == 'C' 
	|| map_copy[line_start][char_start - 1] == 'E')
		flood_the_map(map_copy, line_start, char_start - 1, c);
	if (map_copy[line_start + 1][char_start] == '0'
	|| map_copy[line_start + 1][char_start] == 'C' 
	|| map_copy[line_start + 1][char_start] == 'E')
		flood_the_map(map_copy, line_start + 1, char_start, c);
	if (map_copy[line_start - 1][char_start] == '0' ||
		map_copy[line_start - 1][char_start] == 'C' ||
		map_copy[line_start - 1][char_start] == 'E')
		flood_the_map(map_copy, line_start - 1, char_start, c);
	return (0);
}

int	is_exit_ok(char **map_copy, int line_start, int char_start, int *e)
{
	if ('E' == map_copy[line_start][char_start])
		e[0]++;
	map_copy[line_start][char_start] = 'O';
	if (map_copy[line_start][char_start + 1] == 'X'
	|| map_copy[line_start][char_start + 1] == 'E')
		is_exit_ok(map_copy, line_start, char_start + 1, e);
	if (map_copy[line_start][char_start - 1] == 'X'
	|| map_copy[line_start][char_start - 1] == 'E')
		is_exit_ok(map_copy, line_start, char_start - 1, e);
	if (map_copy[line_start + 1][char_start] == 'X'
	|| map_copy[line_start + 1][char_start] == 'E')
		is_exit_ok(map_copy, line_start + 1, char_start, e);
	if (map_copy[line_start - 1][char_start] == 'X' ||
		map_copy[line_start - 1][char_start] == 'E')
		is_exit_ok(map_copy, line_start - 1, char_start, e);
	return (0);
}
