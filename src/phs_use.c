/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phs_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 02:02:04 by olnytim           #+#    #+#             */
/*   Updated: 2023/06/03 19:16:03 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_backdrop(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->size_y)
	{
		x = 0;
		while (x < game->size_x)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->ph->background, x, y);
			x += X_SCALE;
		}
		y += Y_SCALE;
	}
}

void	ft_creation(t_game *game)
{
	game->map->rows = 0;
	game->map->cols = 0;
	while (game->map->rows < game->size_y / Y_SCALE)
	{
		game->map->cols = 0;
		while (game->map->cols < game->size_x / X_SCALE)
		{
			if (game->map->map[game->map->rows][game->map->cols] == 'P')
				ft_put_pl(game);
			else if (game->map->map[game->map->rows][game->map->cols] == '1')
				ft_put_ph(game, "phs/walls.xpm");
			else if (game->map->map[game->map->rows][game->map->cols] == 'C')
				ft_put_ph(game, "phs/meat.xpm");
			else if (game->map->map[game->map->rows][game->map->cols] == 'E')
				ft_put_ph(game, "phs/onepiece.xpm");
			game->map->cols++;
		}
		game->map->rows++;
	}
}
