/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   fills.c                                            |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/05/21 15:27:46 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/05/29 01:09:44 by olnytim                /     \       *   */
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
			"phs/player_right.xpm", &img_width, &img_height);
	game->ph->look_left = mlx_xpm_file_to_image(game->mlx,
			"phs/player_left.xpm", &img_width, &img_height);
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
	game->player_x = game->map->cols;
	game->player_y = game->map->rows;
	mlx_put_image_to_window(game->mlx, game->window, game->ph->look_right,
		game->player_x * X_SCALE, game->player_y * Y_SCALE);
}
