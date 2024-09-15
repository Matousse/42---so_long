/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:26:36 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:47:57 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct pos
{
	int	x;
	int	y;
}		t_pos;

void	flood_fill(char **tab, int x, int y, t_game *game_tab)
{
	if (tab[y][x] == '1' || tab[y][x] == 'X')
		return ;
	if (tab[y][x] == 'C')
		(game_tab->nb_coin)++;
	if (tab[y][x] == 'E')
	{
		(game_tab->is_exit)++;
		return ;
	}
	tab[y][x] = 'X';
	flood_fill(tab, x + 1, y, game_tab);
	flood_fill(tab, x, y + 1, game_tab);
	flood_fill(tab, x - 1, y, game_tab);
	flood_fill(tab, x, y - 1, game_tab);
}

t_pos	where_is_p(char **tab)
{
	int		x;
	int		y;
	t_pos	exit_pos;

	exit_pos.x = -1;
	exit_pos.y = -1;
	y = 0;
	while (y > -1)
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
			{
				exit_pos.x = x;
				exit_pos.y = y;
				return (exit_pos);
			}
			x++;
		}
		y++;
	}
	return (exit_pos);
}

int	flood_fill_maestro(t_game *game_tab)
{
	t_pos	exit_pos;

	game_tab->nb_coin = 0;
	game_tab->is_exit = 0;
	exit_pos.x = -1;
	exit_pos.y = -1;
	exit_pos = where_is_p(game_tab->ff_tab);
	if (exit_pos.x == -1 && exit_pos.y == -1)
		return (ft_printf("Error\nP not found on the map.\n"), -1);
	flood_fill(game_tab->ff_tab, exit_pos.x, exit_pos.y, game_tab);
	if (game_tab->nb_coin != game_tab->c)
		return (ft_printf("Error\nAt least one collectible was not reachable\n"),
			-1);
	if (game_tab->is_exit == 0)
		return (ft_printf("Error\nExit is not reachable\n"), -1);
	return (0);
}
