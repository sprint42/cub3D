/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:38:31 by mcha              #+#    #+#             */
/*   Updated: 2022/06/09 19:31:13 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

/*
**	User define headers
*/
# include "parse.h"

/*
**	Process
*/
void	proc_mlx(t_map_info **info);

/*
**	Check
*/
void	is_texture_valid(t_map_info **info);

/*
**	Bind
*/
void	init_mlx(t_map_info **info);
void	init_texture(t_map_info **info);
void	init_cardinal_east(t_map_info **info);
void	init_cardinal_west(t_map_info **info);
void	init_cardinal_south(t_map_info **info);
void	init_cardinal_north(t_map_info **info);
void	bind_cardinal_east(t_map_info **info);
void	bind_cardinal_west(t_map_info **info);
void	bind_cardinal_south(t_map_info **info);
void	bind_cardinal_north(t_map_info **info);

/*
**	Free
*/
void	destroy_texture(t_map_info **info);

#endif