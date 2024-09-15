/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_the_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:19:04 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:51:21 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_ber_extension(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '.')
		i++;
	if (map[i] == '\0')
	{
		ft_printf("Error\nFile doesn't have any extension");
		return (-1);
	}
	if (map[i] == '.')
	{
		if (ft_strncmp(&map[i], ".ber", 4) == 0)
			return (1);
		else
			ft_printf("Error\nWrong file extension");
	}
	return (-1);
}

int	is_map_charset(char letter)
{
	if (letter == '0' || letter == '1')
		return (0);
	if (letter == 'P' || letter == 'E' || letter == 'C')
		return (0);
	return (-1);
}

int	verify_the_map(char *map, t_game *game_tab)
{
	int		fd;
	char	*line;

	if (has_ber_extension(map) == -1)
		return (-1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nImpossible to open the map file"), -1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (ft_printf("Error\nThe map is not valid"), -1);
	}
	if (verify_first_line_and_save_width(line, game_tab) == -1)
		return (purge_gnl_and_close_fd(line, fd));
	if (verify_other_lines(line, game_tab, fd) == -1)
		return (close(fd), -1);
	close(fd);
	return (0);
}

int	purge_gnl_and_close_fd(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (-1);
}
