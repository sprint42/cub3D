/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_meaningful.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:09:39 by mcha              #+#    #+#             */
/*   Updated: 2022/06/06 23:18:08 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	proc_meaningful(t_map_info *info, char *buf)
{
	if (is_texture(info, buf))
		bind_texture(info, buf);
	else if (is_color(info, buf))
		;
}
