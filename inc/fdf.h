/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:16:00 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/11 02:24:55 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#ifndef READ_BUFFER_SIZE
# define READ_BUFFER_SIZE 512
#endif

# define SIN_30 0.866025
# define COS_30 0.5

# define W_HE 1600
# define W_WI 1800
# define SCALE 20

/*
 *	t_cell is a struct that contains info of each point on the map. 
 *
 *	Value represents 'z' coordinate in fact and i know it must be defined in a more clear way.
 *	Nevertheless i'm too lazy to modify every fucking file in project, so i'll leave it be.
 *
 *	in t_map x is width and y is height of map. Sorry for my bad naming again.
 */

typedef struct s_cell {
	int	x;
	int	y;
	int	value;
	int	color;
}	t_cell;

typedef struct s_map {
	t_cell	**inf;
	int		x;
	int		y;
}	t_map;

typedef struct s_pos {
	int	x0;
	int	y0;
	int	z0;
	int	x1;
	int	y1;
	int	z1;
}	t_pos;

typedef struct s_line {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;
	
typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bitbp;
	int		l_len;
	int		endian;
}	t_mlx;

typedef struct s_data {
	t_map	map;
	t_mlx	mlx;
}	t_data;

void	read_data(t_data *data, const char *file);
t_pos	isometric_points(t_cell first, t_cell second);

void	init(t_mlx *data);
int		count_line(const char *file);
int		count_space(const char *file);
void	free_double(char **str0, char *str1);
void	free_map(t_map *map);
void	put_pixel_to_img(t_data *data, int x, int y, int color);
void	draw_map(t_data *data);

int	abs(int	num);

#endif
