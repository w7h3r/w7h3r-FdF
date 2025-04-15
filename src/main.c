/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:19:06 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/14 01:05:13 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (-1);
	read_data(&data, argv[1]);
	init(&data);
	draw_map(&data);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
	hook_inputs(&data);
	mlx_loop(data.mlx.mlx);
}
