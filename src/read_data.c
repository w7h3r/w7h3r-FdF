/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:50:15 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/14 01:17:08 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	err_exit(const char *err)
{
	perror(err);
	exit(1);
}

char	*get_file_content(const char *file)
{
	int		fd;
	char	*con;
	char	*line_buffer;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_exit("Error: Invalid fd");
	con = ft_strdup("");
	if (!con)
		err_exit("Error: strdup() failed");
	line_buffer = get_next_line(fd);
	while (line_buffer)
	{
		temp = ft_strjoin(con, line_buffer);
		if (!temp)
		{
			free(con);
			free(line_buffer);
			err_exit("Error: ft_strjoin failed");
		}
		free(con);
		free(line_buffer);
		line_buffer = get_next_line(fd);
		con = temp;
	}
	close(fd);
	return (con);
}

static char	**split_content(char *con)
{
	return (ft_split(con, '\n'));
}

static	int	get_map_h(char **map)
{
	int	nl_count;

	nl_count = 0;
	while (map[nl_count])
		nl_count++;
	return (nl_count);
}

static	int	get_map_w(char *map)
{
	char	**split_buffer;
	int		units;
	
	split_buffer = ft_split(map, ' ');
	units = 0;
	while (split_buffer[units])
		units++;
	free_double(split_buffer, NULL);
	return (units);
}

t_cell	insert_cell(char *cell_data, int col, int row)
{
	t_cell 	cell;
	char	**units;

	cell.x = col;
	cell.y = row;
	cell.value = 0;
	cell.color = 0xFFFFFF;
	if (ft_strchr(cell_data, ','))
	{
		units = ft_split(cell_data, ',');
		if (units && units[0])
			cell.value = ft_atoi(units[0]);
		if (units && units[1])
			cell.color = ft_atoi_base(&units[1][2], 16);
		free_double(units, NULL);
	}
	else
		cell.value = ft_atoi(cell_data);
	return (cell);
}

t_cell	**alloc_insert_cells(char **map, int h, int w)
{
	t_cell	**cells;
	char	**split_buffer;
	int		row;
	int		col;

	cells = malloc(sizeof(t_cell *) * h);
	if (!cells)
		err_exit("Error: Malloc failed. init_map_cells(): 86");
	row = 0;
	while (row < h)
	{
		split_buffer = ft_split(map[row], ' ');
		col = 0;
		cells[row] = malloc(sizeof(t_cell) * w);
		if (!cells[row])
		{
			err_exit("Error: Malloc failed. init_map_cells(): 95");
		}
		while (col < w)
		{
			cells[row][col] = insert_cell(split_buffer[col], col, row);
			col++;
		}
		free_double(split_buffer, NULL);
		row++;
	}
	return (cells);
}

void	read_data(t_data *data, const char *file)
{
	char	*file_con;
	char	**t_map;
	int		w;
	int		h;

	file_con = get_file_content(file);
	if (!file_con)
		err_exit("Error: File read failed");
	t_map = split_content(file_con);
	if (!t_map)
		err_exit("Error: Content split failed");
	h = get_map_h(t_map);
	w = get_map_w(t_map[0]);
	data->map.inf = alloc_insert_cells(t_map, h, w);
	data->map.x = w;
	data->map.y = h;
	free(file_con);
	free_double(t_map, NULL);
}
