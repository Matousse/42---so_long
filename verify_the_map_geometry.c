/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_the_map_geometry.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:19:12 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:50:30 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_first_line_and_save_width(char *line, t_game *game_tab)
{
	game_tab->tab_width = 0;
	if (line[game_tab->tab_width] == '\n')
		return (ft_printf("Error\nFirst character of the line is backslash n"),
			-1);
	if (line[game_tab->tab_width] == '\0')
		return (ft_printf("Error\nFirst line is empty"), -1);
	while (line[game_tab->tab_width] != '\0'
		&& line[game_tab->tab_width] != '\n')
	{
		if (line[game_tab->tab_width] != '1')
			return (ft_printf("Error\nFirst line of the map is not full of '1'"),
				-1);
		game_tab->tab_width++;
	}
	return (0);
}

int	verify_other_lines(char *line, t_game *game_tab, int fd)
{
	int	i;

	game_tab->tab_height = 0;
	while (line)
	{
		game_tab->tab_height++;
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (is_map_charset(line[i]) == -1)
				return (free_and_print(line, fd,
						"Error\nThe map contains an incorrect identifier\n"),
					-1);
			i++;
		}
		if (i != game_tab->tab_width)
			return (free_and_print(line, fd,
					"Error\nThe map is not a rectangle\n"), -1);
		if (line[0] != '1' || line[i - 1] != '1')
			return (free_and_print(line, fd,
					"Error\nThe map is not closed by '1's\n"), -1);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	free_and_print(char *line, int fd, char *str)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (ft_printf("%s", str));
}
