/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_db_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:21:39 by mcha              #+#    #+#             */
/*   Updated: 2022/06/06 16:22:45 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_db_arr(char **arr)
{
	size_t	sz;
	size_t	idx;

	idx = 0;
	sz = ft_db_arr_sz(arr);
	while (idx < sz)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}
