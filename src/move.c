/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   move.c                                             |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/05/26 16:59:58 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/05/29 01:06:54 by olnytim                /     \       *   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_pl_motion(t_game *game, char loc, int turn)
{
	if (loc == 'x' && turn == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ph->look_right,
			game->player_x * X_SCALE, game->player_y * Y_SCALE);
	}
	if (loc == 'x' && turn == -1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ph->look_left,
			game->player_x * X_SCALE, game->player_y * Y_SCALE);
	}
	if (loc == 'y' && turn == -1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ph->look_right,
			game->player_x * X_SCALE, game->player_y * Y_SCALE);
	}
	if (loc == 'y' && turn == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ph->look_left,
			game->player_x * X_SCALE, game->player_y * Y_SCALE);
	}
}

static void	ft_take(t_game *game, char loc, int turn)
{
	game->collected++;
	game->map->map[game->player_y][game->player_x] = '0';
	mlx_put_image_to_window(game->mlx, game->window, game->ph->background,
		game->player_x * X_SCALE, game->player_y * Y_SCALE);
	ft_pl_motion(game, loc, turn);
}

static void	ft_move(t_game *game, char loc, int turn)
{
	mlx_put_image_to_window(game->mlx, game->window, game->ph->background,
		game->player_x * X_SCALE, game->player_y * Y_SCALE);
	if (loc == 'y'
		&& game->map->map[game->player_y + 1 * turn][game->player_x] != '1'
		&& (game->map->map[game->player_y + 1 * turn][game->player_x] != 'E'
		|| game->collected == game->map->bf))
		game->player_y += 1 * turn;
	else if (loc == 'x'
		&& game->map->map[game->player_y][game->player_x + 1 * turn] != '1'
		&& (game->map->map[game->player_y][game->player_x + 1 * turn] != 'E'
		|| game->collected == game->map->bf))
		game->player_x += 1 * turn;
	else if (loc == 'y'
		&& game->map->map[game->player_y + 1 * turn][game->player_x] == 'E'
		&& game->collected != game->map->bf)
		ft_printf("Continue your journey until you collect all bonefires");
	else if (loc == 'x'
		&& game->map->map[game->player_y][game->player_x + 1 * turn] == 'E'
		&& game->collected != game->map->bf)
		ft_printf("Continue your journey until you collect all bonefires");
	ft_pl_motion(game, loc, turn);
	if (game->map->map[game->player_y][game->player_x] == 'C')
		ft_take(game, loc, turn);
	mlx_do_sync(game->mlx);
	ft_printf("You made %d moves\n", game->counter++);
}

int	ft_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_end(game);
	else if (keycode == 119)
		ft_move(game, 'y', -1);
	else if (keycode == 115)
		ft_move(game, 'y', 1);
	else if (keycode == 100)
		ft_move(game, 'x', 1);
	else if (keycode == 97)
		ft_move(game, 'x', -1);
	if (game->map->map[game->player_y][game->player_x] == 'E')
	{
		ft_printf("You win!\n");
		ft_printf("You collected %d bonefires\n", game->collected);
		ft_printf("You made %d moves\n", game->counter);
		exit(0);
	}
	return (0);
}
