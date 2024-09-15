/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:19:16 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:47:01 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_exit(t_game *game_tab)
{
	free_tab(game_tab);
	if (game_tab->win)
		mlx_destroy_window(game_tab->mlx, game_tab->win);
	if (game_tab->mlx)
	{
		mlx_destroy_display(game_tab->mlx);
		free(game_tab->mlx);
	}
	exit(0);
	return (0);
}

int	free_tab(t_game *game_tab)
{
	int	i;

	i = 0;
	while (game_tab->tab[i])
	{
		free(game_tab->tab[i]);
		i++;
	}
	free(game_tab->tab);
	i = 0;
	while (game_tab->ff_tab[i])
	{
		free(game_tab->ff_tab[i]);
		i++;
	}
	free(game_tab->ff_tab);
	return (0);
}

int	parsing_dispatcher(char **argv, t_game *game_tab)
{
	if (verify_the_map(argv[1], game_tab) == -1)
		return (-1);
	if (parse_the_map(argv[1], game_tab) == -1)
		return (-1);
	parse_the_ff_map(argv[1], game_tab);
	if (verify_pce(game_tab->tab, game_tab) == -1)
		return (free_tab(game_tab), -1);
	if (flood_fill_maestro(game_tab) == -1)
		return (free_tab(game_tab), -1);
	ft_printf("The map was correctly parsed\n");
	return (0);
}

int	key_hook(int keycode, t_game *game_tab)
{
	if (keycode == 119)
		move_player(game_tab, 0, -1);
	else if (keycode == 115)
		move_player(game_tab, 0, 1);
	else if (keycode == 97)
		move_player(game_tab, -1, 0);
	else if (keycode == 100)
		move_player(game_tab, 1, 0);
	else if (keycode == 65307)
		clean_exit(game_tab);
	display_map(game_tab);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game_tab;

	if (argc != 2)
		return (ft_printf("Error\nNumber of parameters incorrect (!= 2)\n"));
	game_tab.collected = 0;
	game_tab.movement = 0;
	game_tab.tab_width = 0;
	if (parsing_dispatcher(argv, &game_tab) == -1)
		return (0);
	game_tab.mlx = mlx_init();
	if (game_tab.mlx == NULL)
		return (ft_printf("Error\nImpossible to initialize MLX\n", -1));
	get_map_dimensions(game_tab.tab, &game_tab.tab_width, &game_tab.tab_height);
	game_tab.win = mlx_new_window(game_tab.mlx, game_tab.tab_width * 32,
			game_tab.tab_height * 32, "Gaming zone");
	if (game_tab.win == NULL)
		return (ft_printf("Error\nFailed to create MLX window\n"), -1);
	display_map(&game_tab);
	mlx_hook(game_tab.win, 2, 1L << 0, key_hook, &game_tab);
	mlx_hook(game_tab.win, 17, 0, clean_exit, &game_tab);
	mlx_loop(game_tab.mlx);
	return (0);
}
