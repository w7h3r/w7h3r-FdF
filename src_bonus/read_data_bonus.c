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

#include "../inc/fdf_bonus.h"
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	get_line_content(char *temp, char **con, char **line_buffer, int fd)
{
	if (!temp)
	{
		free(*con);
		free(*line_buffer);
		err_exit("Error: ft_strjoin failed");
	}
	free(*con);
	*con = temp;
	free(*line_buffer);
	*line_buffer = get_next_line(fd);
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
		get_line_content(temp, &con, &line_buffer, fd);
	}
	close(fd);
	return (con);
}

t_cell	insert_cell(char *cell_data, int col, int row)
{
	t_cell	cell;
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
	row = -1;
	while (++row < h)
	{
		split_buffer = ft_split(map[row], ' ');
		col = 0;
		cells[row] = malloc(sizeof(t_cell) * w);
		if (!cells[row])
			err_exit("Error: Malloc failed. init_map_cells(): 95");
		while (col < w)
		{
			cells[row][col] = insert_cell(split_buffer[col], col, row);
			col++;
		}
		free_double(split_buffer, NULL);
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
	if (is_map_rectangle(t_map, w))
	{
		free_double(t_map, file_con);
		err_exit("Error: Map must be rectangle shape");
	}
	data->map.inf = alloc_insert_cells(t_map, h, w);
	data->map.x = w;
	data->map.y = h;
	free(file_con);
	free_double(t_map, NULL);
}
