/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:35:47 by mcha              #+#    #+#             */
/*   Updated: 2022/06/09 16:23:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "minilib.h"

int	main(int ac, char **av)
{
	t_map_info	*map_info;

	map_info = NULL;
	check_main_arg(ac, av);
	malloc_info(&map_info);
	proc_map(&map_info, av[1]);
	proc_mlx(&map_info);
	free_map(&map_info);
	return (1);
}
