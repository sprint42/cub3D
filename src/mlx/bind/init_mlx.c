/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:45:43 by mcha              #+#    #+#             */
/*   Updated: 2022/06/12 16:12:44 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	init_mlx(t_map_info **info)
{
	(*info)->mlx_ptr = mlx_init();
	if (!(*info)->mlx_ptr)
	{
		error_print(ERROR_MLX_INIT);
		exit(EXIT_FAILURE);
	}
}
