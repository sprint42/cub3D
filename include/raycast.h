/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:09:57 by yejin             #+#    #+#             */
/*   Updated: 2022/06/13 00:09:59 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "minilib.h"

# define winW 4096
# define winH 2048
# define texW 64
# define texH 64

// init_state.
void	init_state(t_map_info *map_info);

#endif