/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:31:31 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/13 17:54:18 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	gnl_strlen(const char *c)
{
	unsigned int	i;

	i = 0;
	if (c == 0)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*gnl_free_imp(char *buffer, char *temp)
{
	if (buffer)
		free(buffer);
	if (temp)
		free(temp);
	return (NULL);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	res = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (res == NULL)
		return (gnl_free_imp((char *)s1, NULL));
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	gnl_free_imp((char *)s1, NULL);
	return (res);
}
