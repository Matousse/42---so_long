/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_the_pce_identifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:19:08 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:51:40 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_there_only_one_e(char **tab)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'E')
				e += 1;
			j++;
		}
		i++;
	}
	if (e != 1)
	{
		ft_printf("Error\nThere is no or more than one exit");
		return (-1);
	}
	return (0);
}

int	is_there_only_one_p(char **tab, t_game *game_tab)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				p += 1;
				game_tab->playerx = j;
				game_tab->playery = i;
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		return (ft_printf("Error\nThere is no or more than one player"), -1);
	return (0);
}

int	is_there_at_least_one_c(char **tab, t_game *game_tab)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				c += 1;
			j++;
		}
		i++;
	}
	if (c < 1)
	{
		ft_printf("Error\nThere is no C in the MAP");
		return (-1);
	}
	game_tab->c = c;
	return (0);
}

int	verify_pce(char **tab, t_game *game_tab)
{
	if (is_there_only_one_e(tab) == -1)
		return (-1);
	if (is_there_only_one_p(tab, game_tab) == -1)
		return (-1);
	if (is_there_at_least_one_c(tab, game_tab) == -1)
		return (-1);
	return (0);
}
