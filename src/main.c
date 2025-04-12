/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:19:06 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/12 21:21:07 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include <stdlib.h>

void	arg_control(char **argv)
{
	char	*s;

	s = ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]));
	if (s == NULL)
	{
		ft_printf("Error: Invalid file format\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (-1);
	arg_control(argv);
	read_data(&data, argv[1]);
	ft_printf("COLOR OF FIRST CELL: %d\n", data.map.inf[0][0].color);
	init(&data);
	draw_map(&data);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
	hook_inputs(&data);
	mlx_loop(data.mlx.mlx);
}
