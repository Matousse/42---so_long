/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:41:52 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/09 12:34:45 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_error(char *big_buff, char *read_buff)
{
	if (big_buff)
		free(big_buff);
	if (!read_buff)
		return (NULL);
	free(read_buff);
	return (NULL);
}

static char	*get_line(char *big_buff)
{
	char	*str;
	int		i;

	i = 0;
	if (!big_buff[i])
		return (NULL);
	while (big_buff[i] && big_buff[i] != '\n')
		i++;
	if (big_buff[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = big_buff[i];
		i--;
	}
	return (str);
}

char	*get_next_buff(char *big_buff)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (big_buff[i] && big_buff[i] != '\n')
		i++;
	if (!big_buff[i])
		return (ft_error(big_buff, 0));
	result = malloc((gt_strlen(big_buff) - i + 1) * sizeof(char));
	if (!result)
		return (ft_error(big_buff, 0));
	i++;
	while (big_buff[i])
		result[j++] = big_buff[i++];
	result[j] = '\0';
	free(big_buff);
	return (result);
}

char	*ft_get_all_text(int fd, char *big_buff)
{
	int		status;
	char	*read_buff;
	char	*temp;

	status = 1;
	read_buff = gt_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buff)
		return (ft_error(big_buff, 0));
	while (status)
	{
		status = read(fd, read_buff, BUFFER_SIZE);
		if (status == -1)
			return (ft_error(big_buff, read_buff));
		read_buff[status] = '\0';
		temp = gt_strjoin(big_buff, read_buff);
		free(big_buff);
		big_buff = temp;
		if (!big_buff)
			return (ft_error(read_buff, 0));
		if (gt_strchr(read_buff, '\n'))
			break ;
	}
	free(read_buff);
	return (big_buff);
}

char	*get_next_line(int fd)
{
	static char	*big_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!big_buff)
		big_buff = gt_calloc(1, sizeof(char));
	if (!big_buff)
		return (NULL);
	big_buff = ft_get_all_text(fd, big_buff);
	if (!big_buff)
		return (NULL);
	line = get_line(big_buff);
	if (!line)
	{
		free(big_buff);
		big_buff = 0;
		return (NULL);
	}
	big_buff = get_next_buff(big_buff);
	return (line);
}
