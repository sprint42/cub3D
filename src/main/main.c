/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:35:47 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 22:25:50 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "minilib.h"
#include "raycast.h"

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
