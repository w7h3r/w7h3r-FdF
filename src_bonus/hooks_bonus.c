/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:40:22 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/12 18:48:10 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/mlx.h"
#include "../inc/fdf_bonus.h"
#include <stdlib.h>

int	close_win(void *param)
{
	t_data	*data;

	data = (void *)param;
	free_data(data);
	exit (0);
}

int	key_hook(int keycode, void *param)
{
	if (keycode == 65307)
		close_win(param);
	return (0);
}

void	hook_inputs(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, close_win, data);
	mlx_key_hook(data->mlx.win, key_hook, data);
}
