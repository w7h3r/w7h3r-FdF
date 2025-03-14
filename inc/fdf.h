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

# define WIN_H 720
# define WIN_W 1280

typedef struct s_cell {
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
	int	x1;
	int	y1;
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
	t_pos	p_pos;
	t_mlx	mlx;
}	t_data;

void	read_data(t_data *data, const char *file);

int		count_line(const char *file);
int		count_space(const char *file);
void	free_double(char **str0, char *str1);
void	free_map(t_map *map);

#endif
