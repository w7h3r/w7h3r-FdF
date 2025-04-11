/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:58:24 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/11 02:33:10 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/ft_printf/include/ft_printf.h"

/*
 * draw_line() is a re-implementation of bressenham's line algorithm to this project.
 */

void put_pixel_to_img(t_data *data, int x, int y, int color)
{
    int *pixel;

    if (x < 0 || y < 0 || x >= W_WI || y >= W_HE)
		return;  // Ekranın dışına taşan piksellere çizim yapma
	pixel = (int *)(data->mlx.addr + (y * data->mlx.l_len + x * (data->mlx.bitbp / 8)));
	*pixel = color;
}

static void	draw_line_controls(t_line *line, t_pos *pos)
{
	if (pos->x0 < pos->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (pos->y0 < pos->y1)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}

void	draw_line(t_data *data, t_pos pos)
{
	t_line line;

	line.dx = abs(pos.x1 - pos.x0);
	line.dy = abs(pos.y1 - pos.y0);
	draw_line_controls(&line, &pos);
	while (1)
	{   
		ft_printf("Put pixel at (%d, %d)\n", pos.x0, pos.y0);
		put_pixel_to_img(data, pos.x0, pos.y0, 0xFFFFFF);
		if (pos.x0 == pos.x1 && pos.y0 == pos.y1)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			pos.x0 += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			pos.y0 += line.sy;
		}
	}
}

void	draw_map(t_data *data)
{
	t_pos	pos;
	int		x;
	int		y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (x < data->map.x - 1)
			{
				pos = isometric_points(data->map.inf[y][x], data->map.inf[y][x + 1]);
				draw_line(data, pos);
			}
			if (y < data->map.y - 1)
			{
				pos = isometric_points(data->map.inf[y][x], data->map.inf[y + 1][x]);
				draw_line(data, pos);
			}
			x++;
		}
		y++;
	}
}
