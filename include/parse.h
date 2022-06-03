/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:35:58 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 18:36:57 by mcha             ###   ########.fr       */
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
# include "../libft/libft.h"
# include "parse_struct.h"

/*
**	Check
*/
void	check_main_arg(int ac, char **av);

/*
**	Struct
*/
void	malloc_info(t_map_info **info);

/*
**	Free
*/
void	free_map(t_map_info *info);

/*
**	Error
*/
void	error_print(int ec);

#endif