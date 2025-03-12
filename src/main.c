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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	t_data	data;

	read_data(&data, argv[1]);
	for (int i = 0; i < data.map.y; i++)
	{
		for(int j = 0; j < data.map.x; j++)
    	{
        	ft_printf("Value at [%d][%d]: %d, Color: %d\n",
            	      i, j,
                	  data.map.inf[i][j].value,    // Print the value
                 	 data.map.inf[i][j].color);  // Print the color
    	}
		ft_printf("\n");
	}
}
