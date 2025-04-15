/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:16:00 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/14 01:04:10 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# ifndef READ_BUFFER_SIZE
#  define READ_BUFFER_SIZE 1024
# endif

# define V_FACTOR 0.21
# define H_FACTOR 0.51

# define W_HE 800
# define W_WI 1200

typedef struct s_cell
{
	int	x;
	int	y;
	int	value;
	int	color;
}	t_cell;

typedef struct s_map
{
	t_cell	**inf;
	int		x;
	int		y;
	int		scale;
}	t_map;

typedef struct s_color
{
	int		steps;
	int		curr_step;
	float	ratio;
	int		color;
}	t_color;

typedef struct s_pos
{
	int	x0;
	int	y0;
	int	z0;
	int	x1;
	int	y1;
	int	z1;
}	t_pos;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bitbp;
	int		l_len;
	int		endian;
}	t_mlx;

typedef struct s_data
{
	t_map	map;
	t_mlx	mlx;
}	t_data;

void	read_data(t_data *data, const char *file);
int		ft_strcspn(char *str, char c);
t_pos	isometric_points(t_map map, t_cell first, t_cell second, float scale);

void	init(t_data *data);
void	free_double(char **str0, char *str1);
void	free_map(t_map *map);
void	free_data(t_data *data);
void	put_pixel_to_img(t_data *data, int x, int y, int color);
void	draw_map(t_data *data);
void	hook_inputs(t_data *data);
float	get_scale(t_map map);
void	get_proj_factor(t_map *map);
void	set_color(t_color *clr);
int		color_inter(float ratio, int f_color, int s_color);

int		abs(int num);
char	**split_content(char *con);
int		get_map_h(char **map);
int		get_map_w(char *map);
int		is_map_rectangle(char **map, int w);

void	err_exit(const char *err);

#endif
