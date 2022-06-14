/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_red_cross.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:35:54 by yejin             #+#    #+#             */
/*   Updated: 2022/06/14 13:19:48 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycast.h"

void	event_red_cross(t_map_info *map_info)
{
	free_map(&map_info);
	exit(EXIT_SUCCESS);
}