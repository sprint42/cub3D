/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:45:26 by mcha              #+#    #+#             */
/*   Updated: 2022/06/13 12:09:31 by mcha             ###   ########.fr       */
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
	ERROR_COMP_NOT_FOUND,
	ERROR_ALREADY_BIND,
	ERROR_NOT_APPROP,
	ERROR_EMPTY_OCCURED,
	ERROR_EMPTY_N_OCCURED,
	ERROR_MAP_PARSE_END,
	ERROR_COMP_AFTER_END,
	ERROR_INVALID_MAP_CHAR,
	ERROR_PLAYER_SPAWN_CNT,
	ERROR_MAP_NOT_EXIST,
	ERROR_XPM,
	ERROR_MLX_INIT,
	ERROR_BIND_FAIL,
};

/*
**	need refact
*/
enum	e_flag
{
	COMP_BIND_DONE = 1 << 1,
	CHECK_BEFORE_MAP = 1 << 2,
	START_MAP_PARSE = 1 << 3,
	END_MAP_PARSE = 1 << 4,
};

enum	e_texture_type
{
	EA = 1,
	WE,
	SO,
	NO
};

enum	e_color_type
{
	F,
	C
};

enum	e_checker_type
{
	UD,
	LR
};

typedef struct t_texture_path
{
	char	*path_e;
	char	*path_w;
	char	*path_s;
	char	*path_n;
}t_texture_path;

typedef struct t_color
{
	unsigned int	f_r;
	unsigned int	f_g;
	unsigned int	f_b;
	unsigned int	c_r;
	unsigned int	c_g;
	unsigned int	c_b;
	unsigned int	f_check;
	unsigned int	c_check;
	unsigned int	f_rgb;
	unsigned int	c_rgb;
}t_color;

typedef struct t_map_ptr
{
	void	*ptr_e;
	void	*ptr_w;
	void	*ptr_s;
	void	*ptr_n;
}t_map_ptr;

typedef struct t_comp
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}t_comp;

typedef struct t_texture
{
	struct t_comp	*comp_e;
	struct t_comp	*comp_w;
	struct t_comp	*comp_s;
	struct t_comp	*comp_n;
}t_texture;

typedef struct s_state
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	t_comp	img_buf;
}	t_state;

typedef struct t_map_info
{
	int						width;
	int						height;
	int						flag;
	char					*wspace;
	char					*valid;
	struct t_texture_path	*path;
	struct t_color			*color;
	struct t_map_ptr		*ptr;
	struct t_texture		*texture;
	char					**map;
	void					*mlx_ptr;
	void					*win_ptr;
	t_state					state;
}	t_map_info;

#endif