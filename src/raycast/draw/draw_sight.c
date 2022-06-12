/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:19 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 01:13:07 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"


void	draw_sight(t_map_info *map_info)
{
	int		i;
	t_ray	ray;

	i = 0;
	while (i < winW)
	{
		ray.camera_pos = -2 * i / (double)winW + 1;
		init_ray(map_info, &ray);
		i++;
	}
}