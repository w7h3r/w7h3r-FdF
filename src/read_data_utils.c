/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:00:15 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/10 15:01:14 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"
#include "../inc/fdf.h"
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

void	free_double(char **str0, char *str1)
{
	int	i;

	if (str0)
	{
		i = 0;
		while (str0[i])
		{
			free(str0[i]);
			i++;
		}
		free(str0);
	}
	if (str1)
		free(str1);
}

void	free_map(t_map *map)
{
    int i;

	i = 0;
    while (i < map->y)
    {
        free(map->inf[i]);
		i++;
    }
    free(map->inf);
}
