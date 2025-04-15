/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:58:24 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/14 00:52:09 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../lib/ft_printf/include/ft_printf.h"

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

static void	line_control(t_pos *pos, t_line *line)
{
	line->e2 = 2 * line->err;
	if (line->e2 > -line->dy)
	{
		line->err -= line->dy;
		pos->x0 += line->sx;
	}
	if (line->e2 < line->dx)
	{
		line->err += line->dx;
		pos->y0 += line->sy;
	}
}

static void	draw_line(t_data *data, t_pos pos, int f_color, int s_color)
{
	t_line	line;
	t_color	clr;

	clr.curr_step = 0;
	line.dx = abs(pos.x1 - pos.x0);
	line.dy = abs(pos.y1 - pos.y0);
	clr.steps = line.dy;
	if (line.dx > line.dy)
		clr.steps = line.dx;
	draw_line_controls(&line, &pos);
	while (1)
	{
		set_color(&clr);
		if (f_color == 0)
			clr.color = 0xFFFFFF;
		else
			clr.color = color_inter(clr.ratio, f_color, s_color);
		put_pixel_to_img(data, pos.x0, pos.y0, clr.color);
		if (pos.x0 == pos.x1 && pos.y0 == pos.y1)
			break ;
		line_control(&pos, &line);
		clr.curr_step++;
	}
}

static void	draw_hv_lines(t_data *data, t_pos *pos, int x, int y)
{
	if (x < data->map.x - 1)
	{
		*pos = isometric_points(data->map.inf[y][x], \
				data->map.inf[y][x + 1], data->map.scale);
		draw_line(data, *pos, data->map.inf[y][x].color, \
				data->map.inf[y][x + 1].color);
	}
	if (y < data->map.y - 1)
	{
		*pos = isometric_points(data->map.inf[y][x], \
				data->map.inf[y + 1][x], data->map.scale);
		draw_line(data, *pos, data->map.inf[y][x].color, \
				data->map.inf[y + 1][x].color);
	}
}

void	draw_map(t_data *data)
{
	t_pos	pos;
	int		x;
	int		y;

	data->map.scale = get_scale(data->map);
	ft_printf("%d", data->map.scale);
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			draw_hv_lines(data, &pos, x, y);
			x++;
		}
		y++;
	}
}
