/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:39:48 by mcha              #+#    #+#             */
/*   Updated: 2022/06/09 17:04:41 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	malloc_ptr(t_map_info **info)
{
	(*info)->ptr = (t_map_ptr *)malloc(sizeof(t_map_ptr));
	if (!((*info)->ptr))
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	(*info)->ptr->ptr_e = NULL;
	(*info)->ptr->ptr_w = NULL;
	(*info)->ptr->ptr_s = NULL;
	(*info)->ptr->ptr_n = NULL;
}
