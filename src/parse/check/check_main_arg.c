/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:34:06 by mcha              #+#    #+#             */
/*   Updated: 2022/06/09 14:43:04 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_ac_lack(int ac)
{
	if (ac != 2)
	{
		error_print(ERROR_AC);
		return (1);
	}
	return (0);
}

static int	is_map_name_not_valid(char **av)
{
	char	*tmp;

	tmp = av[1];
	if (tmp && ft_strlen(tmp) < 4)
	{
		error_print(ERROR_AV);
		return (1);
	}
	while (*tmp)
		tmp++;
	tmp -= 4;
	if (tmp && ft_strncmp(tmp, ".cub", 4))
	{
		error_print(ERROR_AV);
		return (1);
	}
	return (0);
}

static int	is_map_not_exist(char **av)
{
	char	*tmp;
	int		fd;

	tmp = av[1];
	fd = open(tmp, O_RDONLY, 0644);
	if (fd < 0)
	{
		error_print(ERROR_FILE_NOT_EXIST);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

void	check_main_arg(int ac, char **av)
{
	if (is_ac_lack(ac))
		exit(EXIT_FAILURE);
	if (is_map_name_not_valid(av))
		exit(EXIT_FAILURE);
	if (is_map_not_exist(av))
		exit(EXIT_FAILURE);
}
