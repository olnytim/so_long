/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:42:24 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/06/03 19:05:27 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_SCALE 64
# define Y_SCALE 64

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char		**map;
	char		*texture;
	int			rows;
	int			cols;
	int			bf;
}				t_map;

typedef struct s_ph
{
	void		*look_left;
	void		*look_right;
	void		*background;
}				t_ph;

typedef struct s_game
{
	t_map		*map;
	t_ph		*ph;
	void		*mlx;
	void		*window;
	int			p_x;
	int			p_y;
	int			size_x;
	int			size_y;
	int			counter;
	int			collected;
}				t_game;

void	ft_error_log(char *str);
void	ft_sizes(t_game *game, char **av);
void	ft_fills_1(t_game *game, t_map *map);
void	ft_fills_2(t_game *game);
void	ft_map_done(t_game *game, char **av);
void	ft_backdrop(t_game *game);
void	ft_put_ph(t_game *game, char *path);
void	ft_put_pl(t_game *game);
void	ft_creation(t_game *game);
void	ft_wins(t_game *game);
int		ft_end(t_game *game);
int		ft_hook(int keycode, t_game *game);

#endif
