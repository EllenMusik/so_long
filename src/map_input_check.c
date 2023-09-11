/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:25:01 by esteiner          #+#    #+#             */
/*   Updated: 2023/07/24 12:57:35 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	test_for_dup_char(char **map_array, char p_or_e)
{
	int	line_count;
	int	char_count;
	int	pe_char;

	char_count = 0;
	line_count = 0;
	pe_char = 0;
	while (map_array[line_count])
	{
		while (map_array[line_count][char_count])
		{
			if (map_array[line_count][char_count] == p_or_e)
			{
				if (pe_char != 0)
					return (write(2, "more than one start or exit\n", 28), 1);
				pe_char++;
			}
			char_count++;
		}
		char_count = 0;
		line_count++;
	}
	if (pe_char == 0)
		return ((write(2, "start or exit is missing\n", 25), 1));
	return (0);
}

int	test_outside_walls(char **map_array)
{
	int	line_count;
	int	char_count;

	line_count = 0;
	char_count = 0;
	while (map_array[line_count][char_count] != '\n')
	{
		if (map_array[line_count][char_count] != '1')
			return (write(2, "not surrounded by walls\n", 24), 1);
		char_count++;
	}
	char_count = 0;
	while (map_array[line_count + 1])
		line_count++;
	while (map_array[line_count][char_count])
	{
		if (map_array[line_count][char_count] != '1')
			return (write(2, "not surrounded by walls\n", 24), 1);
		char_count++;
	}
	side_walls(map_array, line_count, char_count);
	return (0);
}

int	side_walls(char **map_array, int line_count, int char_count)
{
	line_count = 0;
	char_count = 0;
	while (map_array[line_count])
	{
		if (map_array[line_count][char_count] != '1')
			return (write(2, "not surrounded by walls\n", 24), 1);
		line_count++;
	}
	line_count = 0;
	while (map_array[line_count][char_count + 1] != '\n')
		char_count++;
	while (map_array[line_count])
	{
		if (map_array[line_count][char_count] != '1')
			return (write(2, "not surrounded by walls\n", 24), 1);
		line_count++;
	}
	return (0);
}

int	free_map_2(char **map_array, int lines)
{
	int	i;

	i = 0;
	while (i < lines && map_array[i])
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
	return (0);
}

size_t	linelen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] && s[x] != '\n')
		x++;
	return (x);
}
