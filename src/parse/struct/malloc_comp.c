/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:39:48 by mcha              #+#    #+#             */
/*   Updated: 2022/06/08 17:44:17 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	malloc_comp(t_map_info **info)
{
	(*info)->comp = (t_map_comp *)malloc(sizeof(t_map_comp));
	if (!((*info)->comp))
	{
		error_print(ERROR_MAL);
		exit(EXIT_FAILURE);
	}
	(*info)->comp->comp_e = NULL;
	(*info)->comp->comp_w = NULL;
	(*info)->comp->comp_s = NULL;
	(*info)->comp->comp_n = NULL;
}
