/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:23:44 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/11 16:00:33 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "/home/dmathis/42cursus/42_utils/mlx/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct game_info
{
	char	**tab;
	char	**ff_tab;
	int		c;
	char	*file_in_one_var;
	int		tab_width;
	int		tab_height;
	int		playerx;
	int		playery;
	int		nb_coin;
	int		is_exit;
	int		collected;
	void	*img;
	void	*mlx;
	void	*win;
	int		movement;

}	t_game;

int		verify_last_line(char *line);
int		parse_the_map(char *map, t_game *game_tab);
int		parse_the_ff_map(char *map, t_game *game_tab);

int		has_ber_extension(char *map);
int		is_map_charset(char letter);
int		verify_first_line_and_save_width(char *line, t_game *game_tab);
int		verify_the_map(char *map, t_game *game_tab);
int		purge_gnl_and_close_fd(char *line, int fd);

int		verify_a_line(char *line, t_game *game_tab);
int		get_first_line_and_verify_it(char *line, int fd, t_game *game_info);
int		verify_other_lines(char *line, t_game *game_tab, int fd);

int		verify_pce(char **tab, t_game *map_informations);
int		is_there_only_one_e(char **tab);
int		is_there_only_one_p(char **tab, t_game *game_info);
int		is_there_at_least_one_c(char **tab, t_game *game_info);

char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);

int		flood_fill_maestro(t_game *game_tab);

void	swap_p_in_map(t_game *game_info, int dx, int dy);
int		move_player(t_game *game_info, int dx, int dy);
int		free_tab(t_game *game_tab);
int		clean_exit(t_game *game_tab);

int		display_map(t_game *game_tab);
void	get_map_dimensions(char **map, int *width, int *height);
int		free_and_print(char *line, int fd, char *str);

#endif
