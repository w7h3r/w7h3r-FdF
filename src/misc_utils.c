/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:19:36 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/11 01:23:06 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../lib/libft/libft.h"

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_strcspn(char *str, char c)
{
	int	target_idx;

	target_idx = 0;
	while (str[target_idx])
	{
		if (str[target_idx] == c)
			break ;
		target_idx++;
	}
	return (target_idx);
}

void	err_exit(const char *err)
{
	perror(err);
	exit(1);
}

char	**split_content(char *con)
{
	return (ft_split(con, '\n'));
}

void	free_double(char **str0, char *str1)
{
	int	i;

	if (str0)
	{
		i = 0;
		while (str0[i])
		{
			free(str0[i]);
			i++;
		}
		free(str0);
	}
	if (str1)
		free(str1);
}
