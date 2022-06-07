/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:44:19 by mcha              #+#    #+#             */
/*   Updated: 2022/06/07 22:32:17 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	set_errno(int ec)
{
	if (ec == ERROR_AC || ec == ERROR_AV)
		errno = 22;
	else if (ec == ERROR_FILE_NOT_EXIST)
		errno = 2;
	else if (ec == ERROR_MAL)
		errno = 12;
	else if (ec == ERROR_COMP_NOT_FOUND || \
			ec == ERROR_ALREADY_BIND || \
			ec == ERROR_NOT_APPROP || \
			ec == ERROR_EMPTY_OCCURED || \
			ec == ERROR_EMPTY_N_OCCURED || \
			ec == ERROR_COMP_AFTER_END || \
			ec == ERROR_INVALID_MAP_CHAR || \
			ec == ERROR_PLAYER_SPAWN_CNT || \
			ec == ERROR_MAP_NOT_EXIST)
		errno = 22;
}

void	error_print(int ec)
{
	set_errno(ec);
	if (ec == ERROR_AC || ec == ERROR_AV)
		perror("Error\nusage: ./cub3D [MAPFILE].cub	");
	else if (ec == ERROR_FILE_NOT_EXIST)
		perror("Error\nmessage: mapfile not exist	");
	else if (ec == ERROR_MAL)
		perror("Error\nmessage: memory allocate failed	");
	else if (ec == ERROR_COMP_NOT_FOUND)
		perror("Error\nmessage: cannot found parse component	");
	else if (ec == ERROR_ALREADY_BIND)
		perror("Error\nmessage: component is already binded	");
	else if (ec == ERROR_NOT_APPROP)
		perror("Error\nmessage: not appropriate component	");
	else if (ec == ERROR_EMPTY_OCCURED || ec == ERROR_MAP_NOT_EXIST)
		perror("Error\nmessage: empty line occured	");
	else if (ec == ERROR_MAP_PARSE_END)
		perror("Error\nmessage: map parse end	");
	else if (ec == ERROR_EMPTY_N_OCCURED)
		perror("Error\nmessage: empty line not occured	");
	else if (ec == ERROR_COMP_AFTER_END)
		perror("Error\nmeesage: something here after map end	");
	else if (ec == ERROR_INVALID_MAP_CHAR)
		perror("Error\nmessage: invalid map character	");
	else if (ec == ERROR_PLAYER_SPAWN_CNT)
		perror("Error\nmessage: player spawn area is more than 1	");
}
