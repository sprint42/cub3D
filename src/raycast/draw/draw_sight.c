/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:19 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 01:10:01 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"


void	draw_sight(t_map_info *map_info)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (i < winW)
	{
		init_ray(map_info, &ray);
		i++;
	}
}