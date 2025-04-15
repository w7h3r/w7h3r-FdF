/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:00:15 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/13 18:12:25 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"
#include "../inc/fdf_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	count_line(const char *file)
{
	int		nl;
	int		fd;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	nl = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		nl++;
		free(temp);
	}
	close(fd);
	return (nl);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->inf)
		return ;
	i = 0;
	while (i < map->y)
	{
		if (map->inf[i])
			free(map->inf[i]);
		i++;
	}
	free(map->inf);
	map->inf = NULL;
}

int	get_map_h(char **map)
{
	int	nl_count;

	nl_count = 0;
	while (map[nl_count])
		nl_count++;
	return (nl_count);
}

int	get_map_w(char *map)
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

int	is_map_rectangle(char **map, int w)
{
	int	exp_len;
	int	curr_len;
	int	row;

	if (!map)
		return (1);
	exp_len = w;
	row = 1;
	while (map[row])
	{
		curr_len = get_map_w(map[row]);
		if (curr_len != exp_len)
			return (1);
		row++;
	}
	return (0);
}
