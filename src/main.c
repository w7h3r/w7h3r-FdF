/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:19:06 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/11 02:43:12 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	printf_map(t_data data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (-1);

	read_data(&data, argv[1]);
	init(&data.mlx);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
	mlx_loop(data.mlx.mlx);
//	printf_map(data);
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
