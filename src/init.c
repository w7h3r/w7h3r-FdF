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

/*
void	init(t_mlx *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W_WI, W_HE, "FdF");
	data->img = mlx_new_image(data->mlx, W_WI, W_HE);
	data->addr = mlx_get_data_addr(data->img, &data->bitbp, \
			&data->l_len, &data->endian);
}
*/

void init(t_mlx *data)
{
    data->mlx = mlx_init();
    if (!data->mlx) {
        ft_printf("Error: mlx_init failed\n");
        return;  // Error handling here
    }
    
    data->win = mlx_new_window(data->mlx, W_WI, W_HE, "FdF");
    if (!data->win) {
        ft_printf("Error: Window creation failed\n");
        return;  // Error handling here
    }
    
    data->img = mlx_new_image(data->mlx, W_WI, W_HE);
    if (!data->img) {
        ft_printf("Error: Image creation failed\n");
        return;  // Error handling here
    }
    
    data->addr = mlx_get_data_addr(data->img, &data->bitbp, &data->l_len, &data->endian);
    if (!data->addr) {
        ft_printf("Error: mlx_get_data_addr failed\n");
        return;  // Error handling here
    }
}

void	free_mlx(t_data *data);
