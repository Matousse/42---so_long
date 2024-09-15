/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:41:03 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 16:15:02 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_p_in_map(t_game *game_tab, int dx, int dy)
{
	game_tab->tab[game_tab->playery + dy][game_tab->playerx + dx] = 'P';
	game_tab->tab[game_tab->playery][game_tab->playerx] = '0';
	game_tab->movement += 1;
	ft_printf("Total of movements :%d\n", game_tab->movement);
}

int	move_player(t_game *game_tab, int dx, int dy)
{
	if (game_tab->tab[game_tab->playery + dy][game_tab->playerx + dx] == '1')
		return (-1);
	if (game_tab->tab[game_tab->playery + dy][game_tab->playerx + dx] == 'E'
		&& game_tab->c != game_tab->collected)
		return (ft_printf("All collectibles weren't collected \n"),
			-1);
	if (game_tab->tab[game_tab->playery + dy][game_tab->playerx + dx] == 'E'
		&& game_tab->c == game_tab->collected)
	{
		ft_printf("OMG IT'S A NO RE, GG WP\n");
		clean_exit(game_tab);
	}
	if (game_tab->tab[game_tab->playery + dy][game_tab->playerx + dx] == 'C')
		game_tab->collected += 1;
	swap_p_in_map(game_tab, dx, dy);
	game_tab->playerx = game_tab->playerx + dx;
	game_tab->playery = game_tab->playery + dy;
	return (0);
}
