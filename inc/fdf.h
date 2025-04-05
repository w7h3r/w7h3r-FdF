/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:16:00 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/14 01:35:48 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#ifndef READ_BUFFER_SIZE
# define READ_BUFFER_SIZE 512
#endif

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
	int		scale;
}	t_map;

typedef struct s_pos {
	int	x0;
	int	y0;
	int	z0;
	int	x1;
	int	y1;
	int	z1;
}	t_pos;

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

int		count_line(const char *file);
int		count_space(const char *file);
void	free_double(char **str0, char *str1);
void	free_map(t_map *map);

#endif
