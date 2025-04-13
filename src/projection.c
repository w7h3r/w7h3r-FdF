/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:08:45 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/14 00:30:05 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../inc/fdf.h"

/*
 * apply_isometric_to_point();
 * is setting points due to cos(30) and sin(30).
 * SCALE is a constant define. This isn't a sustainable practice though.
 * 
 * in isometric points();
 * Multiply the x and y points positions as scale,
 * apply isometric projection to points
 * and shift the map through the center of the window.
 */

static void	apply_isometric_to_point(int *x, int *y, int z, int scale)
{
	int	base_x;
	int	base_y;

	base_x = *x;
	base_y = *y;
	*x = (base_x - base_y) * H_FACTOR;
	*y = (base_x + base_y) * V_FACTOR - ((float)z * scale / 10);
}

void	get_proj_factor(t_map *map)
{
	if (map->y * map->x > 200)
		map->factor = 4;
	else
		map->factor = 2 + ((int)map->scale / 10);
}

float	get_scale(t_map map)
{
	float	x_scale;
	float	y_scale;

	x_scale = (float)W_WI / map.x;
	y_scale = (float)W_HE / map.y;
	if (x_scale >= y_scale)
	{
		if (y_scale - 30 > 0)
			return (y_scale - 30);
		else
			return (y_scale);
	}
	else
		return (y_scale - 30);
}

t_pos	isometric_points(t_cell first, t_cell second, float scale, int factor)
{
	t_pos	pos;

	(void)factor;
	first.x *= scale;
	first.y *= scale;
	second.x *= scale;
	second.y *= scale;
	apply_isometric_to_point(&first.x, &first.y, first.value, scale);
	apply_isometric_to_point(&second.x, &second.y, second.value, scale);
	first.x += W_WI / 2;
	first.y += W_HE / 2;
	second.x += W_WI / 2;
	second.y += W_HE / 2;
	pos.x0 = first.x;
	pos.y0 = first.y;
	pos.z0 = first.value;
	pos.x1 = second.x;
	pos.y1 = second.y;
	pos.z1 = second.value;
	return (pos);
}
