/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:50:15 by muokcan           #+#    #+#             */
/*   Updated: 2025/02/28 18:53:22 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static unsigned int	nl_counter(int fd)
{
	char			temp[READ_BUFFER_SIZE];
	unsigned int	nl_count;
	unsigned int	i;
	int				bytes_read;

	nl_count = 0;
	bytes_read = read(fd, temp, READ_BUFFER_SIZE);
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (temp[i] == '\n')
				nl_count++;
			i++;
		}
		bytes_read = read(fd, temp, READ_BUFFER_SIZE);
	}
	return (nl_count);
}

int		space_counter(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	return (i);
}

int		*get_line(t_data *map_data, int fd)
{
	char	*buffer;
	char	**temp;
	int		i;

	buffer = get_next_line(fd);
	temp = ft_split(buffer, ' ');
	i = 0;
	i = space_counter(buffer);
	if (i > 0)
	{
		map_data->map_info = malloc(sizeof(int *) * (i + 1));
		map_data->color_map = malloc(sizeof(int *) * (i + 1));
		if (!map_data->map_info || !map_data->color_map)
			exit(0);
	}
}

void	read_map_data(t_data *map_data, const char *file)
{
	unsigned int	nl;
	int				fd;
	unsigned int	i;

	nl = nl_counter(fd);
	if (nl > 0)
	{
		map_data->map_info = malloc(sizeof(int **) * (nl + 1));
		if (!map_data->map_info)
			exit(0);
	}
	while (nl--)
	{
		map_data->map_info[i] = get_line(map_data, fd);
	}
}
