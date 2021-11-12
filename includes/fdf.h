/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <eparviai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:27:29 by eparviai          #+#    #+#             */
/*   Updated: 2020/06/29 00:01:22 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Required system headers
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

/*
** Required user headers
*/

# include "mlx.h"
# include "libft.h"
# include "keys.h"

/*
** Value Macros (self explanatory)
*/

# define MAX_X			(10)
# define MAX_ZOOM		(5)
# define DEFAULT_ZOOM	(2)
# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)

/*
** FDF Structures
**
** t_mlx   : required minilibx arguments.
** t_image : variables to be used for creation of the image (map).
**           data -> Image information.
**           size -> move from one line to another in the image.
**           endian -> Stores the Endian of the system, defining how to
**			 store the color
**           bpp -> Bits-per-pixel.
** t_map   : values used to manipulate the fdf map.
** t_color : define the color, rgb value (24-bits).
** t_fdf   : nested structure that calls all of the other structures.
*/

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_image
{
	int		*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct	s_map
{
	int		**values;
	int		width;
	int		height;
	int		coord_y;
	int		coord_z;
	int		y0;
	int		y1;
	int		z0;
	int		z1;
	int		zoom;
	int		isometric;
	double	x_value;
	double	angle_y;
	double	angle_z;
}				t_map;

typedef struct	s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_image	image;
	int		color;
}				t_fdf;

/*
** Function list
*/

void			output_error(int error_nbr);
void			read_fdf(char *argv, t_fdf *fdf);
int				fdf_draw(t_fdf *fdf);
int				fdf_keys(int keycode, t_fdf *fdf);
void			randomize_color(t_fdf *fdf);

#endif
