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

/* 
 * It's not finished yet.
 *
 * There is a problem; if you give program a 100 column wide row, it count 0 to 100, which is 101.
 * And don't forget to fix 100.000's of ridiculous leaks.
 *
 * Also ft_atoi_base is a new function and might be unstable, check that. If it works, don't touch!!!
 *
 */

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
		exit(-1);
	}
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
		res.color = ft_atoi_base(split_buffer[1], 16);
	}
	else
	{
		split_buffer = ft_split(cell, ',');
		res.value = ft_atoi(split_buffer[0]);
		res.color = ft_atoi_base("0xFFFFFF", 16);
	}
		free_double(split_buffer, NULL);
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
			map->inf[row][col] = insert_cells(split_buffer[col]);
			//ft_printf("split_buffer[%d]: %s\n", col, split_buffer[col]);
			col++;
		}
		row++;
	}
	//ft_printf("VALUE: %d  COLOR: %d", map->inf[3][2].value, map->inf[3][2].color);
	free_double(split_buffer, temp);
	close (fd);
}

void	read_data(t_data *data, const char *file)
{
	int	nl_count;
	int	row;

	nl_count = count_line(file);
	data->map.y = nl_count;
	//ft_printf("%d\n", data->map.y);
	data->map.x = count_line_lenght(file);
	//ft_printf("%d\n", data->map.x);
	data->map.inf = (t_cell **)malloc(sizeof(t_cell *) * data->map.y);
	if (!data->map.inf)
		exit(0);
	row = 0;
	while (row < data->map.y)
	{
		data->map.inf[row] = (t_cell *)malloc(sizeof(t_cell) * data->map.x);
		if (!data->map.inf[row])
		{
			while (row--)
				free(data->map.inf[row]);
			free(data->map.inf);
			exit(1);
		}
		row++;
	}
	insert_map(&data->map, file);
}
