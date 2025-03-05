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
#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	count_line(int fd)
{
	int		nl;
	char	*temp;

	nl = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		else
			nl++;
		free(temp);
	}
	return (nl);
}

char	*insert_cell(char *str, _Bool i)
{

}

int		count_space(char *str)
{
	int	space_count;

	space_count = 0;
	while (*str)
	{
		if (*str == ' ')
			space_count++;
		str++;
	}
	return (space_count);
}

void	insert_lines(t_data *data, int fd, int line_)
{
	char	**temp;
	char	*line;
	int		i;
	int		spc;

	line = get_next_line(fd);
	temp = ft_split(line, ' ');
	spc = count_space(line);
	free(line);
	i = 0;
	while (temp[i])
	{
		data->map.cells[line_] = malloc(sizeof(int *) * (spc + 1));
		data->map.cells[line_][i].value = ft_atoi(insert_cell(temp[i], 0));
		data->map.cells[line_][i].color = ft_atoi(insert_cell(temp[i], 1));
		i++;
	}
}

void	read_map(t_data *map, const char *file)
{
	int	fd;
	int	nl;
	int	i;

	fd = open(file, O_RDONLY);
	close(fd);
	fd = open(file, O_RDONLY);
	nl = count_line(fd);
	i = 0;
	while (i < nl)
	{
		insert_lines(map, fd, i);
		i++;
	}
}
