/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:08:45 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/12 20:48:48 by muokcan          ###   ########.fr       */
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
 * Multiply the x and y points positions as scale, apply isometric projection to points
 * and shift the map through the center of the window.
 */
static void	apply_isometric_to_point(int *x, int *y, int z, int z_scale)
{
	int	base_x;
	int	base_y;

	(void)z_scale;
	base_x = *x;
	base_y = *y;
	*x = (base_x - base_y) * H_FACTOR;
	*y = (base_x + base_y) * V_FACTOR - z;
}

void	calculate_z_scale(t_map *map)
{
	int	col;
	int	row;
	int	min;
	int	max;

	min = map->inf[0][0].value;
	max = map->inf[0][0].value;
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			if (min > map->inf[row][col].value)
				min = map->inf[row][col].value;
			if (max < map->inf[row][col].value)
				max = map->inf[row][col].value;
			col++;
		}
		row++;
	}
	map->z_scale = max - min;
}

t_pos	isometric_points(t_cell first, t_cell second, int z_scale)
{
	t_pos	pos;

	first.x *= SCALE;
	first.y *= SCALE;
	second.x *= SCALE;
	second.y *= SCALE;
	apply_isometric_to_point(&first.x, &first.y, first.value, z_scale);
	apply_isometric_to_point(&second.x, &second.y, second.value, z_scale);
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
