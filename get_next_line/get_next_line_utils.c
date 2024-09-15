/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:56:21 by dmathis           #+#    #+#             */
/*   Updated: 2024/06/12 23:47:02 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

size_t	gt_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	gt_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	*gt_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	totalsize;

	if (nmemb == 0 || size == 0)
	{
		s = malloc(0);
		return (s);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	totalsize = (nmemb * size);
	s = (void *)malloc(totalsize);
	if (s == NULL)
		return (NULL);
	gt_bzero(s, totalsize);
	return (s);
}

char	*gt_strjoin(char const *s1, char const *s2)
{
	int		i_s1;
	int		i_s2;
	char	*dest;

	i_s1 = 0;
	i_s2 = 0;
	while (s1[i_s1])
		i_s1++;
	while (s2[i_s2])
		i_s2++;
	dest = malloc(sizeof(char) * (i_s1 + i_s2) + 1);
	if (dest == NULL)
		return (NULL);
	i_s1 = -1;
	i_s2 = 0;
	while (s1[++i_s1])
		dest[i_s1] = s1[i_s1];
	while (s2[i_s2])
		dest[i_s1++] = s2[i_s2++];
	dest[i_s1] = '\0';
	return (dest);
}

char	*gt_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	c = (unsigned char)(c % 256);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}
