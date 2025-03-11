/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:50:15 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/10 15:33:09 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		count_line_lenght(const char *file)
{
	int		len;
	int		fd;
	char	*temp;
	char	**split_buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	temp = get_next_line(fd);
	if (!temp)
	{
		close(fd);
		exit(-1);
	}
	split_buffer = ft_split(temp, ' ');
	len = 0;
	while (split_buffer[len])
		len++;
	free_double(split_buffer);
	free (temp);
	close(fd);
	return (len);
}

t_cell	insert_cells(char *cell)
{
	t_cell	res;
	char	**split_buffer;

	split_buffer = ft_split(cell, ',');
	res.value = ft_atoi(split_buffer[0]);
	res.color = ft_atoi_base(split_buffer[1], 16);
	free_double(split_buffer);
	return (res);
}

void	insert_map(t_map *map, const char *file)
{
	char	*temp;
	char	**split_buffer;
	int		fd;
	int		row;
	int		col;

	fd = open(file, O_RDONLY);
	row = 0;
	while (row < map->y)
	{
		temp = get_next_line(fd);
		//ft_printf("ROW: %d TEMP: %s\n", row, temp);
		if (!temp)
			break ;
		split_buffer = ft_split(temp, ' ');
		col = 0;
		while (col < map->x)
		{
			map->map_info[row][col] = insert_cells(split_buffer[col]);
			//ft_printf("split_buffer[%d]: %s\n", col, split_buffer[col]);
			col++;
		}
		row++;
	}
	ft_printf("VALUE: %d  COLOR: %d", map->map_info[3][2].value, map->map_info[3][2].color);
	free(temp);
	free_double(split_buffer);
	close (fd);
}

void	read_data(t_data *data, const char *file)
{
	int	nl_count;
	int	row;

	nl_count = count_line(file);
	data->map.y = nl_count;
	data->map.x = count_line_lenght(file);
	data->map.map_info = (t_cell **)malloc(sizeof(t_cell *) * data->map.y);
	if (!data->map.map_info)
		exit(0);
	row = 0;
	while (row < data->map.y)
	{
		data->map.map_info[row] = (t_cell *)malloc(sizeof(t_cell) * data->map.x);
		if (!data->map.map_info[row])
		{
			while (row--)
				free(data->map.map_info[row]);
			free(data->map.map_info);
			exit(1);
		}
		row++;
	}
	insert_map(&data->map, file);
}

