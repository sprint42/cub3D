#ifndef RAYCAST_H
# define RAYCAST_H

# include "minilib.h"

typedef struct s_state
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	t_comp	img_buf;
}	t_state

#endif