/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:35:47 by mcha              #+#    #+#             */
/*   Updated: 2022/06/08 18:13:38 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int ac, char **av)
{
	t_map_info	*map_info;

	map_info = NULL;
	check_main_arg(ac, av);
	malloc_info(&map_info);
	proc_map(&map_info, av[1]);
	free_map(&map_info);
	return (1);
}
