/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:44:19 by mcha              #+#    #+#             */
/*   Updated: 2022/06/06 23:18:06 by mcha             ###   ########.fr       */
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
	else if (ec == ERROR_COMP_NOT_FOUND)
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
}
