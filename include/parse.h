/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:35:58 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 21:28:53 by mcha             ###   ########.fr       */
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

/*
**	Check
*/
void	check_main_arg(int ac, char **av);
int		is_texture(t_map_info *info, char *buf);

/*
**	Proc
*/
void	proc_map(t_map_info *info, char *file_name);
void	proc_meaningful(t_map_info *info, char *buf);

/*
**	Struct
*/
void	malloc_info(t_map_info **info);
void	malloc_texture(t_map_info **info);

/*
**	Free
*/
void	free_map(t_map_info *info);
void	free_info_wspace(char *wspace);
void	free_info_texture(t_texture *texture);

/*
**	Error
*/
void	error_print(int ec);

/*
**	Util
*/
char	*get_next_line(int fd, char **ret);

#endif