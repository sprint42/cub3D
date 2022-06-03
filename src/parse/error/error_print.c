/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:44:19 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 18:16:30 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	error_print(int ec)
{
	if (ec == ERROR_AC || ec == ERROR_AV)
	{
		errno = 22;
		perror("Error\nusage: ./cub3D [MAPFILE].cub	");
	}
	else if (ec == ERROR_FILE_NOT_EXIST)
	{
		errno = 2;
		perror("Error\nmessage: mapfile not exist	");
	}
	else if (ec == ERROR_MAL)
	{
		errno = 12;
		perror("Error\nmessage: memory allocate failed	");
	}
}
