/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:08:45 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/14 00:50:20 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

static void	apply_isometric_to_point(int *x, int *y, int z, float scale)
{
	int	base_x;
	int	base_y;

	base_x = *x;
	base_y = *y;
	*x = (base_x - base_y) * H_FACTOR;
	*y = (base_x + base_y) * V_FACTOR - (z * scale / 10);
}

float	get_scale(t_map map)
{
	float	x_scale;
	float	y_scale;

	x_scale = ((float)W_WI - 120) / map.x;
	y_scale = ((float)W_HE - 80) / map.y;
	if (x_scale >= y_scale)
		return (x_scale);
	else
		return (y_scale);
}

t_pos	isometric_points(t_map map, t_cell first, t_cell second, float scale)
{
	t_pos	pos;

	first.x *= scale;
	first.y *= scale;
	second.x *= scale;
	second.y *= scale;
	apply_isometric_to_point(&first.x, &first.y, first.value, scale);
	apply_isometric_to_point(&second.x, &second.y, second.value, scale);
	first.x += W_WI / 2;
	first.y += (W_HE / 2) - (map.y / 2);
	second.x += W_WI / 2;
	second.y += (W_HE / 2) - (map.y / 2);
	pos.x0 = first.x;
	pos.y0 = first.y;
	pos.z0 = first.value;
	pos.x1 = second.x;
	pos.y1 = second.y;
	pos.z1 = second.value;
	return (pos);
}
