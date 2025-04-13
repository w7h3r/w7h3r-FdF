/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:35:26 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/13 18:27:00 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	free_data(t_data *data)
{
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	if (data->mlx.mlx)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
	}
	free_map(&data->map);
}

void	err_exit_init(t_data *data, const char *err_msg)
{
	ft_printf("%s\n", err_msg);
	free_data(data);
	exit(1);
}

void	init(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		err_exit_init(data, "Error: Can't initialize mlx");
	data->mlx.win = mlx_new_window(data->mlx.mlx, W_WI, W_HE, "FdF");
	if (!data->mlx.win)
		err_exit_init(data, "Error: Can't initialize window");
	data->mlx.img = mlx_new_image(data->mlx.mlx, W_WI, W_HE);
	if (!data->mlx.img)
		err_exit_init(data, "Error: Can't initialize image");
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bitbp, \
			&data->mlx.l_len, &data->mlx.endian);
	if (!data->mlx.addr)
		err_exit_init(data, "Error: Can't take the image addr");
}
