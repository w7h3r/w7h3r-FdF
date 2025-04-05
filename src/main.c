/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:19:06 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/14 01:36:55 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	printf_map(t_data data);

void	init_window(t_data *data)
{
	data->mlx.mlx = mlx_init();
	//data->mlx.win = mlx_new_window(data->mlx.mlx, WIN_W, WIN_H, "AAAAAAAAAAAAa");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->map.x, data->map.y);
	mlx_loop(data->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (-1);

	read_data(&data, argv[1]);
	printf_map(data);
	init_window(&data);
	free_map(&data.map);
}

void	printf_map(t_data data)
{
	for (int i = 0; i < data.map.y; i++)
	{
		for(int j = 0; j < data.map.x; j++)
    	{
        	ft_printf("Value at [%d][%d]: x:%d y:%d z:%d, Color: %d\n",
            	      i, j,
					  data.map.inf[i][j].x,
					  data.map.inf[i][j].y,
                	  data.map.inf[i][j].value,    // Print the value
                 	 data.map.inf[i][j].color);  // Print the color
    	}
		ft_printf("\n");
	}
	ft_printf("X: %d    Y: %d", data.map.x, data.map.y);
}
