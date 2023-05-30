/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   so_long.c                                          |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/05/21 15:20:36 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/05/29 00:58:31 by olnytim                /     \       *   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_printf("This is the end\n");
	exit(1);
}

static int	ft_screen(t_game *game)
{
	ft_fills_2(game);
	ft_backdrop(game);
	ft_creation(game);
	mlx_hook(game->window, 17, 1L << 2, ft_end, game);
	mlx_key_hook(game->window, ft_hook, game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_map	map;

	if (ac == 2)
	{
		ft_sizes(&game, av);
		map.map = ft_calloc(game.size_y + 1, sizeof(char *));
		if (!map.map)
			ft_error_log("Calloc failed\n");
		ft_fills_1(&game, &map);
		ft_map_done(&game, av);
		game.mlx = mlx_init();
		if (!game.mlx)
			ft_error_log("Error with mlx_init");
		game.window = mlx_new_window(game.mlx, game.size_x,
				game.size_y, "./so_long");
		ft_screen(&game);
		mlx_loop(game.mlx);
		exit(1);
	}
	else
		ft_printf("Wrong number of argc\n");
}
