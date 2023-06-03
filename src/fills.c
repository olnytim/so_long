/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fills.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:27:46 by olnytim           #+#    #+#             */
/*   Updated: 2023/06/03 19:15:44 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// file will contain info about addresses

void	ft_fills_1(t_game *game, t_map *map)
{
	game->map = map;
	game->counter = 0;
	game->collected = 0;
}

void	ft_fills_2(t_game *game)
{
	int		img_width;
	int		img_height;
	t_ph	*phs;

	phs = malloc(sizeof(t_ph));
	if (!phs)
		ft_error_log("Malloc failed\n");
	game->ph = phs;
	game->ph->background = mlx_xpm_file_to_image(game->mlx,
			"phs/floor.xpm", &img_width, &img_height);
	game->ph->look_right = mlx_xpm_file_to_image(game->mlx,
			"phs/luffy_right.xpm", &img_width, &img_height);
	game->ph->look_left = mlx_xpm_file_to_image(game->mlx,
			"phs/luffy_left.xpm", &img_width, &img_height);
}

void	ft_put_ph(t_game *game, char *path)
{
	int	img_width;
	int	img_height;

	game->map->texture = mlx_xpm_file_to_image(game->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->window, game->map->texture,
		game->map->cols * X_SCALE, game->map->rows * Y_SCALE);
}

void	ft_put_pl(t_game *game)
{
	game->p_x = game->map->cols;
	game->p_y = game->map->rows;
	mlx_put_image_to_window(game->mlx, game->window, game->ph->look_right,
		game->p_x * X_SCALE, game->p_y * Y_SCALE);
}
