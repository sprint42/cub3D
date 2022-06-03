/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:15:31 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 21:46:15 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_texture_syntax(t_map_info *info, char *buf)
{
	char	*tmp;
	char	**res;

	tmp = ft_strtrim(buf, info->wspace);
	printf("tmp: %s\n", tmp);
	res = ft_split(tmp, ' ');
	printf("arrsz : %zu\n", ft_db_arr_sz(res));
	while (*res)
	{
		printf("res: %s\n", *res);
		res++;
	}
	return (0);
}

int	is_texture(t_map_info *info, char *buf)
{
	is_texture_syntax(info, buf);
	return (0);
}
