/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:07:01 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/12 20:54:43 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

static int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

static int	get_b(int color)
{
	return (color & 0xFF);
}

static int	get_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	set_color(t_color *clr)
{
	if (clr->steps == 0)
		clr->ratio = 0.0f;
	else
		clr->ratio = (float)clr->curr_step / (float)clr->steps;
}

int	color_inter(float ratio, int f_color, int s_color)
{
	int	r;
	int	g;
	int	b;

	r = get_r(f_color) + (get_r(s_color) - get_r(f_color)) * ratio;
	g = get_g(f_color) + (get_g(s_color) - get_g(f_color)) * ratio;
	b = get_b(f_color) + (get_b(s_color) - get_b(f_color)) * ratio;
	return (get_rgb(r, g, b));
}
