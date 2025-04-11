/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:08:45 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/11 01:22:06 by muokcan          ###   ########.fr       */
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

static void	apply_isometric_to_point(int *x, int *y, int z)
{
	int	base_x;
	int	base_y;

	base_x = *x;
	base_y = *y;
	*x = (base_x - base_y) * COS_30;
	*y = (base_x + base_y) * SIN_30 - z;
}

t_pos	isometric_points(t_cell first, t_cell second)
{
	t_pos pos;

	first.x *= SCALE;
	first.y *= SCALE;
	second.x *= SCALE;
	second.y *= SCALE;
	apply_isometric_to_point(&first.x, &first.y, first.value);
	apply_isometric_to_point(&second.x, &second.y, second.value);
	first.x += W_WI / 2 - (5 * SCALE);
	first.y += W_HE / 2 - (5 * SCALE + 245);
	second.x += W_WI / 2 - (5 * SCALE);
	second.y += W_HE / 2 - (5 * SCALE + 245);
	pos.x0 = first.x;
	pos.y0 = first.y;
	pos.z0 = first.value;
	pos.x1 = second.x;
	pos.y1 = second.y;
	pos.z1 = second.value;
	return (pos);
}
