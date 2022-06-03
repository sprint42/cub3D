/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:45:26 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 18:38:16 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_STRUCT_H
# define PARSE_STRUCT_H

enum	e_parse_error
{
	ERROR_AC = 1,
	ERROR_AV,
	ERROR_FILE_NOT_EXIST,
	ERROR_MAL,
};

typedef struct t_texture
{
	char	*texture_e;
	char	*texture_w;
	char	*texture_s;
	char	*texture_n;
}t_texture;

typedef struct t_map_info
{
	char				*wspace;
	struct t_texture	*texture;
}t_map_info;

#endif