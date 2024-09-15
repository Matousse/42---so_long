/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:56:15 by dmathis           #+#    #+#             */
/*   Updated: 2024/06/12 23:32:43 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	gt_strlen(const char *str);
void	gt_bzero(void *s, size_t n);
void	*gt_calloc(size_t count, size_t size);
char	*gt_strjoin(char const *s1, char const *s2);
char	*gt_strchr(const char *str, int c);

#endif
