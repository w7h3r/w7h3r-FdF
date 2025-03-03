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

void	read_data(t_data *data, const char *file)
{
	char			*temp;
	unsigned int	nl;
	int				fd;
	int				i;

	fd = open(file, O_RDONLY);
	nl = nl_counter(fd);
	if (nl > 0)
	{
		data->pos_info = malloc(sizeof(char **) * (nl + 1));
		data->pos_info[nl] = NULL;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < nl)
	{
		temp = get_next_line(fd);
		data->pos_info[i] = ft_split(temp, ' ');
		free(temp);
		i++;
	}
}
