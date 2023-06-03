/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:03:42 by olnytim           #+#    #+#             */
/*   Updated: 2023/06/03 19:16:06 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// file which will count sizes and contain error_log

void	ft_error_log(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

static int	ft_char_counter(int fd)
{
	int		counter;
	char	*str;

	counter = 0;
	str = get_next_line(fd);
	if (!str)
		ft_error_log("Empty file\n");
	while (str[counter] != '\n' && str[counter])
		++counter;
	return (counter);
}

static int	ft_rows_counter(int fd, size_t length)
{
	char	*str;
	int		counter;

	counter = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if ((ft_strlen(str) < length / X_SCALE)
			|| (ft_strlen(str) == 1 && *str != '\n'))
		{
			free(str);
			ft_error_log("Invalid map\nTry to use correct map\n");
		}
		else
		{
			free(str);
			++counter;
		}
	}
	return (counter);
}

void	ft_sizes(t_game *game, char **av)
{
	int	fd;
	char	*temp;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error_log("Wrong file\nTry to use correct file\n");
	temp = ft_strrchr(av[1], '.');
	if (!temp || ft_strncmp(temp, ".ber", 5) != 0)
		ft_error_log("Try to use file with '.ber' ending\n");
	game->size_x = ft_char_counter(fd) * X_SCALE;
	game->size_y = ft_rows_counter(fd, game->size_x) * Y_SCALE;
	close(fd);
}
