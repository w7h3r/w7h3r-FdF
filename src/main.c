/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:19:06 by muokcan           #+#    #+#             */
/*   Updated: 2025/02/28 18:52:31 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/fdf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	read_map(&data, argv[1]);
}
