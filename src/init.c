/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:35:26 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/11 02:42:41 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	err_exit_init(t_data *data)
{
	(void)data;
	return ;
}

void	init(t_data *data)
{
    data->mlx.mlx = mlx_init();
    if (!data->mlx.mlx)
		err_exit_init(data);
	data->mlx.win = mlx_new_window(data->mlx.mlx, W_WI, W_HE, "FdF");
    if (!data->mlx.win)
		err_exit_init(data);
   	data->mlx.img = mlx_new_image(data->mlx.mlx, W_WI, W_HE);
    if (!data->mlx.img)
		err_exit_init(data);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bitbp, \
			&data->mlx.l_len, &data->mlx.endian);
    if (!data->mlx.addr)
		err_exit_init(data);
}

void	free_mlx(t_data *data);
