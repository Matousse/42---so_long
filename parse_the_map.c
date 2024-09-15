/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:28:19 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:49:57 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i++] != '1')
			return (ft_printf("Error\nThe last line is not full of '1's"), -1);
	}
	return (0);
}

int	file_to_char(char *map_file, t_game *game_tab)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	game_tab->file_in_one_var = ft_strdup("");
	if (!game_tab->file_in_one_var)
		return (close(fd), -1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(game_tab->file_in_one_var, line);
		free(game_tab->file_in_one_var);
		if (!temp)
			return (free(line), close(fd), -1);
		game_tab->file_in_one_var = temp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	parse_the_map(char *str, t_game *game_tab)
{
	int	i;

	i = 0;
	if (file_to_char(str, game_tab) == -1)
		return (-1);
	game_tab->tab = ft_split(game_tab->file_in_one_var, '\n');
	free(game_tab->file_in_one_var);
	if (verify_last_line(game_tab->tab[game_tab->tab_height - 1]) == -1)
	{
		while (i < game_tab->tab_height)
			free(game_tab->tab[i++]);
		free(game_tab->tab);
		return (-1);
	}
	return (0);
}

int	parse_the_ff_map(char *str, t_game *game_tab)
{
	int	i;

	i = 0;
	if (file_to_char(str, game_tab) == -1)
		return (-1);
	game_tab->ff_tab = ft_split(game_tab->file_in_one_var, '\n');
	free(game_tab->file_in_one_var);
	if (verify_last_line(game_tab->ff_tab[game_tab->tab_height - 1]) == -1)
	{
		while (i >= 0)
			free(game_tab->ff_tab[i--]);
		free(game_tab->ff_tab);
		return (-1);
	}
	return (0);
}
