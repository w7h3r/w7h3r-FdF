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

static int	insert_line(char *str)
{
	return (0);
}

void	read_data(t_data *data, int fd)
{
	unsigned int	new_line;
	unsigned int	i;

	new_line = nl_counter(fd);
	if (new_line > 0)
	{
		data->pos_info = malloc(sizeof(char *) * (new_line + 1));
		data->pos_info[new_line] = NULL;
	}
	i = 0;
	while (data->pos_info[i] != NULL)
	{
		data->pos_info[i] = get_next_line(fd);
		i++;
	}
}
