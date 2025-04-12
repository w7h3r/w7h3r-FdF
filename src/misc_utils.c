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
