/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:31:21 by muokcan           #+#    #+#             */
/*   Updated: 2024/12/03 12:31:21 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char			*get_next_line(int fd);
char			*gnl_strchr(const char *s, int c);
char			*gnl_strjoin(char const *s1, char const *s2);
char			*gnl_free_imp(char *buffer, char *temp);
unsigned int	gnl_strlen(const char *c);

#endif
