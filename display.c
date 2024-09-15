/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:47:38 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 15:47:22 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tiles(t_game *game_tab, int x, int y)
{
	int	img_width;
	int	img_height;

	if (game_tab->tab[y][x] == '1')
		game_tab->img = mlx_xpm_file_to_image(game_tab->mlx, "xpm/wall.xpm",
				&img_width, &img_height);
	else if (game_tab->tab[y][x] == '0')
		game_tab->img = mlx_xpm_file_to_image(game_tab->mlx, "xpm/floor.xpm",
				&img_width, &img_height);
	else if (game_tab->tab[y][x] == 'P')
		game_tab->img = mlx_xpm_file_to_image(game_tab->mlx, "xpm/player.xpm",
				&img_width, &img_height);
	else if (game_tab->tab[y][x] == 'C')
		game_tab->img = mlx_xpm_file_to_image(game_tab->mlx, "xpm/coin.xpm",
				&img_width, &img_height);
	else if (game_tab->tab[y][x] == 'E')
		game_tab->img = mlx_xpm_file_to_image(game_tab->mlx, "xpm/entry.xpm",
				&img_width, &img_height);
	if (game_tab->img == NULL)
		return ((void)ft_printf("Error\nFailed to load image for a tile\n"));
	mlx_put_image_to_window(game_tab->mlx, game_tab->win, game_tab->img, x * 32,
		y * 32);
	mlx_destroy_image(game_tab->mlx, game_tab->img);
}

void	get_map_dimensions(char **map, int *width, int *height)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		y++;
	}
	*width = x;
	*height = y;
}

int	display_map(t_game *game_tab)
{
	int	y;
	int	x;

	y = 0;
	while (y < game_tab->tab_height)
	{
		x = 0;
		while (x < game_tab->tab_width)
		{
			display_tiles(game_tab, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
