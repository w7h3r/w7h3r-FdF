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

int	count_line_lenght(const char *file)
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
		exit(1);
	}
	temp[ft_strcspn(temp, '\n')] = '\0';
	split_buffer = ft_split(temp, ' ');
	len = 0;
	while (split_buffer[len])
		len++;
	free_double(split_buffer, temp);
	close(fd);
	return (len);
}

t_cell	insert_cells(char *cell)
{
	t_cell	res;
	char	**split_buffer;

	if (ft_strchr(cell, ','))
	{
		split_buffer = ft_split(cell, ',');
		if (!split_buffer || !split_buffer[0])
			err_exit("Error: Cell split failed");
		res.value = ft_atoi(split_buffer[0]);
		if (split_buffer[1] && ft_strlen(split_buffer[1]) > 2 &&
				split_buffer[1][0] == '0' && split_buffer[1][1] == 'x')
			res.color = ft_atoi_base(&split_buffer[1][2], 16);
		free_double(split_buffer, NULL);
	}
	else
	{
		res.value = ft_atoi(cell);
		res.color = ft_atoi_base("0xFFFFFF", 16);
	}
	return (res);
}

int	check_fd(t_map *map, const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		err_exit("Error: Invalid fd value");
	}
	return (fd);
}


void	insert_map(t_map *map, const char *file)
{
	char	*temp;
	char	**split_buffer;
	int		fd;
	int		row;
	int		col;

	fd = check_fd(map, file);
	row = 1;
	while (row < map->y)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		split_buffer = ft_split(temp, ' ');
		col = -1;
		while (++col < map->x)
		{
			map->inf[row][col] = insert_cells(split_buffer[col]);
			map->inf[row][col].x = col;
			map->inf[row][col].y = row;
		}
		free_double(split_buffer, temp);
		row++;
	}
	close (fd);
}

void	gnl_cleaner(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	count_words(const char *line, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == sep)
			i++;
		if (line[i] && line[i] != sep)
		{
			count++;
			while (line[i] && line[i] != sep)
				i++;
		}
	}
	return (count);
}

int	is_map_rect(const char *file)
{
	int		fd;
	char	*line;
	int		exp_len;
	int		curr_len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	exp_len = count_words(line, ' ');
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		curr_len = count_words(line, ' ');
		if (curr_len != exp_len)
		{
			gnl_cleaner(fd);
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	allocate_map(t_data *data)
{
	int	row;

	data->map.inf = (t_cell **)malloc(sizeof(t_cell *) * data->map.y);
	if (!data->map.inf)
		err_exit("Error: Map allocation failed");
	row = 0;
	while (row < data->map.y)
	{
		data->map.inf[row] = (t_cell *)malloc(sizeof(t_cell) * data->map.x);
		if (!data->map.inf[row])
		{
			while (--row)
				free(data->map.inf[row]);
			free(data->map.inf);
			err_exit("Error: Map allocation failed");
		}
		row++;
	}
}

void	read_data(t_data *data, const char *file)
{

	if (!(is_map_rect(file)))
		exit(1);
	data->map.y = count_line(file);
	data->map.x = count_line_lenght(file);
	allocate_map(data);
	insert_map(&data->map, file);
	ft_printf("%d\n", data->map.inf[0][0].color);
}
