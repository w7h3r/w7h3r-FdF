/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:19:06 by muokcan           #+#    #+#             */
/*   Updated: 2025/02/28 18:52:31 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	free_map(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->pos_info[i])
	{
		j = 0;
		while (map->pos_info[i][j])
		{
			free(map->pos_info[i][j]);
			map->pos_info[i][j] = NULL;
			j++;
		}
		free(map->pos_info[i]);
		map->pos_info[i] = NULL;
		i++;
	}
	free(map->pos_info);
	map->pos_info = NULL;
}

int	main(int argc, char **argv)
{
	t_data	map;

	read_data(&map, argv[1]);
	free_map(&map);
}
