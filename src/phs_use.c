/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   phs_use.c                                          |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/05/22 02:02:04 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/05/22 02:02:05 by olnytim                /     \       *   */
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
				ft_put_ph(game, "phs/bonefire.xpm");
			else if (game->map->map[game->map->rows][game->map->cols] == 'E')
				ft_put_ph(game, "phs/exit.xpm");
			game->map->cols++;
		}
		game->map->rows++;
	}
}
