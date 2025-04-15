/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:33:48 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/13 02:34:41 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	int	*pixel;

	if (x < 0 || y < 0 || x >= W_WI || y >= W_HE)
		return ;
	pixel = (int *)(data->mlx.addr + \
			(y * data->mlx.l_len + x * (data->mlx.bitbp / 8)));
	*pixel = color;
}

void	set_color(t_color *clr)
{
	if (clr->steps == 0)
		clr->ratio = 0.0f;
	else
		clr->ratio = (float)clr->curr_step / (float)clr->steps;
}
