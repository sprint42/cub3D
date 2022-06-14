/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:35:58 by mcha              #+#    #+#             */
/*   Updated: 2022/06/14 19:38:30 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*
**	System headers
*/
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

/*
**	User define headers
*/
# include "parse_struct.h"
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

/*
**	Check
*/
int		is_color(char *buf);
int		is_color_value_nbr(char **arr);
void	check_main_arg(int ac, char **av);
void	check_map_valid_pre(t_map_info **info);
void	check_map_valid_after(t_map_info **info);
int		is_texture(t_map_info **info, char *buf);
void	check_player_spawn_cnt(t_map_info **info);
void	check_texture_and_color(t_map_info **info);
int		check_component_all_bind(t_map_info **info);

/*
**	Proc
*/
void	proc_map_manufact(t_map_info **info);
void	proc_map(t_map_info **info, char *file_name);
void	proc_meaningful(t_map_info **info, char *buf);

/*
**	Bind
*/
void	bind_map(t_map_info **info, char *buf);
void	bind_color(t_map_info **info, char *buf);
void	bind_texture(t_map_info **info, char *buf);
void	bind_color_value(t_map_info **info, char *value, int type);

/*
**	Struct
*/
void	malloc_ptr(t_map_info **info);
void	malloc_info(t_map_info **info);
void	malloc_comp(t_map_info **info);
void	malloc_color(t_map_info **info);
void	malloc_texture(t_map_info **info);

/*
**	Free
*/
void	free_db_arr(char **arr);
void	free_map(t_map_info **info);
void	free_info_wspace(t_map_info *info);
void	free_info_valid(t_map_info *info);
void	free_info_texture_path(t_map_info *info);
void	free_info_color(t_map_info *info);
void	free_texture_ptr(t_map_info *info);
void	free_texture(t_map_info *info);

/*
**	Error
*/
void	err_exit(int ec);
void	error_print(int ec);

/*
**	Util
*/
char	*get_next_line(int fd, char **ret);

#endif