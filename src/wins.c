/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wins.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:40:33 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/06/03 19:16:12 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wins(t_game *game)
{
	if (game->map->map[game->p_y][game->p_x] == 'E')
	{
		ft_printf("You win!\n");
		ft_printf("You collected %d meat\n", game->collected);
		ft_printf("You made %d moves\n", game->counter);
		exit(0);
	}
}
