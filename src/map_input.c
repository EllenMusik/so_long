/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:49:16 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/21 16:52:16 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**validate_the_map(char **map_file, t_data *data_ptr)
{
	char	**map_array;
	int		number_of_lines;
	int		collectible_count;

	collectible_count = 0;
	number_of_lines = iterate_the_map(map_file, &collectible_count);
	if (number_of_lines < 2)
		return (NULL);
	data_ptr->c_count = collectible_count;
	map_array = create_the_map(number_of_lines, map_file);
	if (!map_array)
		return (NULL);
	if (1 == test_for_dup_char(map_array, 'P'))
		return (free_map(map_array), NULL);
	if (1 == test_for_dup_char(map_array, 'E'))
		return (free_map(map_array), NULL);
	if (1 == test_outside_walls(map_array))
		return (free_map(map_array), NULL);
	if (1 == find_valid_path(map_array, collectible_count, 0))
		return (free_map(map_array), NULL);
	return (map_array);
}

int	iterate_the_map(char **map_file, int *collectible_count)
{
	int		number_of_lines;
	int		c;
	char	str;
	int		fd;

	number_of_lines = 1;
	fd = open(*map_file, O_RDONLY);
	c = 1;
	while (c == 1)
	{
		c = read(fd, &str, 1);
		if (!(str == '1' || str == '0' || str == 'C'
				|| str == 'E' || str == 'P' || str == '\n'))
			return (write(2, "wrong character in map\n", 23), 0);
		if (str == 'C')
			collectible_count[0]++;
		if (str == '\n')
			number_of_lines++;
	}
	close (fd);
	return (number_of_lines);
}

char	**create_the_map(int number_of_lines, char **map_file)
{
	char	**map_array;
	int		i;
	size_t	line_lenght;
	int		fd;

	i = 0;
	line_lenght = 0;
	map_array = malloc(sizeof(char *) * (number_of_lines + 1));
	fd = open(*map_file, O_RDONLY);
	while (i < number_of_lines)
	{
		map_array[i] = get_next_line(fd);
		if (!map_array[i])
		{
			free_map(map_array);
			return (write(2, "could not read line\n", 20), NULL);
		}
		if (1 == check_line_length(line_lenght, map_array, i))
			return (free_map_2(map_array, i), NULL);
		line_lenght = linelen(map_array[i]);
		i++;
	}
	map_array[i] = NULL;
	close(fd);
	return (map_array);
}

int	check_line_length(size_t line_lenght, char **map_array, int i)
{
	if (line_lenght != 0)
	{
		if (line_lenght != linelen(map_array[i]))
		{
			write(2, "map is not rectangular\n", 23);
			return (1);
		}
	}
	return (0);
}

void	print_map(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		printf("%s", map_array[i]);
		i++;
	}
	printf("\n");
	printf("\n");
}
