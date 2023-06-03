/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:58 by olnytim           #+#    #+#             */
/*   Updated: 2023/06/03 19:15:50 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_pl_motion(t_game *game, char loc, int turn)
{
	if (loc == 'x' && turn == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ph->look_right,
			game->p_x * X_SCALE, game->p_y * Y_SCALE);
	}
	if (loc == 'x' && turn == -1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ph->look_left,
			game->p_x * X_SCALE, game->p_y * Y_SCALE);
	}
	if (loc == 'y' && turn == -1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ph->look_right,
			game->p_x * X_SCALE, game->p_y * Y_SCALE);
	}
	if (loc == 'y' && turn == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->ph->look_left,
			game->p_x * X_SCALE, game->p_y * Y_SCALE);
	}
}

static void	ft_take(t_game *game, char loc, int turn)
{
	game->collected++;
	game->map->map[game->p_y][game->p_x] = '0';
	mlx_put_image_to_window(game->mlx, game->window, game->ph->background,
		game->p_x * X_SCALE, game->p_y * Y_SCALE);
	ft_pl_motion(game, loc, turn);
}

static void	ft_move1(t_game *game, char loc, int turn)
{
	mlx_put_image_to_window(game->mlx, game->window, game->ph->background,
		game->p_x * X_SCALE, game->p_y * Y_SCALE);
	if (loc == 'y' && game->map->map[game->p_y + 1 * turn][game->p_x]
		!= '1' && (game->map->map[game->p_y + 1 * turn][game->p_x] != 'E'
		|| game->collected == game->map->bf))
	{
		game->p_y += 1 * turn;
		ft_printf("You made %d moves\n", game->counter++);
	}
	else if (loc == 'x' && game->map->map[game->p_y][game->p_x + 1 * turn]
		!= '1' && (game->map->map[game->p_y][game->p_x + 1 * turn] != 'E'
		|| game->collected == game->map->bf))
	{
		game->p_x += 1 * turn;
		ft_printf("You made %d moves\n", game->counter++);
	}
	else if (loc == 'y' && game->map->map[game->p_y + 1 * turn][game->p_x]
		== 'E' && game->collected != game->map->bf)
		ft_printf("Continue your journey until you collect all bonefires\n");
	else if (loc == 'x' && game->map->map[game->p_y][game->p_x + 1 * turn]
		== 'E' && game->collected != game->map->bf)
		ft_printf("Continue your journey until you collect all bonefires\n");
}

static void	ft_move2(t_game *game, char loc, int turn)
{
	ft_pl_motion(game, loc, turn);
	if (game->map->map[game->p_y][game->p_x] == 'C')
		ft_take(game, loc, turn);
	mlx_do_sync(game->mlx);
}

int	ft_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_end(game);
	else if (keycode == 13)
	{
		ft_move1(game, 'y', -1);
		ft_move2(game, 'y', -1);
	}
	else if (keycode == 1)
	{
		ft_move1(game, 'y', 1);
		ft_move2(game, 'y', 1);
	}
	else if (keycode == 2)
	{
		ft_move1(game, 'x', 1);
		ft_move2(game, 'x', 1);
	}
	else if (keycode == 0)
	{
		ft_move1(game, 'x', -1);
		ft_move2(game, 'x', -1);
	}
	ft_wins(game);
	return (0);
}
