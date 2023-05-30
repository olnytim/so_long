/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   map_parse_checker.c                                |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/05/16 04:50:00 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/05/29 01:07:22 by olnytim                /     \       *   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// file wiil contain parser and map checker

static void	ft_map_parse(t_game *game, char **av)
{
	int		fd;
	int		i;
	int		bytes;
	char	temp[2];

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error_log("Open error\n");
	bytes = 1;
	i = 0;
	temp[1] = '\0';
	while (bytes == 1)
	{
		bytes = read(fd, temp, 1);
		if (bytes != 1)
			break ;
		if (temp[0] != '\n' && temp[0] != '\0')
			game->map->map[i] = ft_strjoin_gnl(game->map->map[i], temp);
		else
			++i;
	}
}

static int	ft_counter(char *str, char c)
{
	int	i;
	int	items;

	i = 0;
	items = 0;
	if (!str)
		return (-1);
	while (str && str[i])
		if (str[i++] == c)
			items++;
	return (items);
}

static void	ft_map_fills_checker(t_game *game)
{
	int	k;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	k = 0;
	game->map->bf = 0;
	while (game->map->map && game->map->map[k])
	{
		exit += ft_counter(game->map->map[k], 'E');
		player += ft_counter(game->map->map[k], 'P');
		game->map->bf += ft_counter(game->map->map[k], 'C');
		++k;
	}
	if (player != 1)
		ft_error_log("Invalid number of players\n");
	if (exit != 1)
		ft_error_log("Invalid number of exits\n");
	if (game->map->bf == 0)
		ft_error_log("Invalid number of bonefires\n");
}

static void	ft_map_edge_checker(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->size_y / Y_SCALE)
	{
		if ((int)ft_strlen(game->map->map[y]) != game->size_x / X_SCALE)
			ft_error_log("Invalid map size");
		x = 0;
		while (x < game->size_x / X_SCALE)
		{
			if (game->map->map[y][x] != '0' && game->map->map[y][x] != '1' &&
				game->map->map[y][x] != 'E' && game->map->map[y][x] != 'C' &&
				game->map->map[y][x] != 'P')
				ft_error_log("Invalid fill of map\n");
			else if ((y == 0 || x == 0) && game->map->map[y][x] != '1')
				ft_error_log("Invalid walls of the map\n");
			else if ((y == (game->size_y / Y_SCALE - 1)
					|| x == (game->size_x / X_SCALE - 1))
				&& game->map->map[y][x] != '1')
				ft_error_log("Invalid walls of the map\n");
			++x;
		}
		++y;
	}
}

void	ft_map_done(t_game *game, char **av)
{
	ft_map_parse(game, av);
	ft_map_fills_checker(game);
	ft_map_edge_checker(game);
}
