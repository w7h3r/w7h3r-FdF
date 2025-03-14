/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:02:08 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/14 01:17:55 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"

int	int_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	pixel_put_to_image(t_data *data, int x, int y, int color)
{
}

void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
	int	x;
	int	y;
	int	x_delta;
	int	y_delta;
	int	err;

	x_delta = int_abs(x0 - x1);
	y_delta = int_abs(y0 - y1);
	err = x_delta - y_delta;

	while (1)
	{
		if (x0 == x1 && y0 == y1)
			break ;

	}
}

void	put_map(t_data *data)
{
}
