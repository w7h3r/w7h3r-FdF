/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:16:00 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/10 16:30:11 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#ifndef READ_BUFFER_SIZE
# define READ_BUFFER_SIZE 512
#endif

typedef struct s_cell {
	int	value;
	int	color;
}	t_cell;

typedef struct s_map {
	t_cell	**map_info;
	int		x;
	int		y;
}	t_map;

typedef struct s_data {
	t_map	map;
}	t_data;

void	read_data(t_data *data, const char *file);

int		count_line(const char *file);
int		count_space(const char *file);
void	free_double(char **str);

#endif
