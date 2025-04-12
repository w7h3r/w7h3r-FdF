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
#include "../inc/fdf.h"
#include <stdlib.h>

int	key_hook(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	(void)data;
	if (keycode == 65307)
	{
		free_data(data);
		exit (0);
	}
	return (0);
}

void	hook_inputs(t_data *data)
{
	mlx_key_hook(data->mlx.win, key_hook, data);
}
