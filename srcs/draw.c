/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <eparviai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:27:29 by eparviai          #+#    #+#             */
/*   Updated: 2020/06/29 00:01:22 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	put_pixel(t_fdf *fdf, int y, int z, double vector)
{
	int		pos;
	int		r;
	int		g;
	int		b;

	b = (int)(fdf->color % 256 + (vector * 2)) > 255 ? 255 : \
		(int)(fdf->color % 256 + vector);
	g = (int)((fdf->color / 256) % 256 + (vector * 2)) > 255 ? 255 : \
		(int)((fdf->color / 256) % 256 + vector);
	r = (int)((fdf->color / 256 / 256) % 256 + (vector * 2)) > 255 ? 255 : \
		(int)((fdf->color / 256 / 256) % 256 + vector);
	if ((y > 0 && z > 0) && (y < WIN_WIDTH && z < WIN_HEIGHT))
	{
		pos = y + (z * WIN_WIDTH);
		fdf->image.data[pos] = (r << 16) | (g << 8) | (b);
	}
}

static	void	fdf_input_pixels_to_line(t_fdf *fdf)
{
	double	y;
	double	z;
	double	delta_y;
	double	delta_z;
	double	vector;

	y = fdf->map.y0;
	z = fdf->map.z0;
	delta_y = fdf->map.y1 - fdf->map.y0;
	delta_z = fdf->map.z1 - fdf->map.z0;
	vector = sqrt((pow(delta_y, 2)) + (pow(delta_z, 2)));
	delta_y /= vector;
	delta_z /= vector;
	while (vector > 0)
	{
		put_pixel(fdf, y, z, vector);
		y += delta_y;
		z += delta_z;
		vector--;
	}
}

/*
** Draws the lines between the points that are designated by the map,
** also takes into consideration the variables that change
** according to user input.
** Direction 0 = horizontal lines, 1 = vertical lines.
*/

static	void	draw_lines(t_fdf *fdf, int y, int z, int direction)
{
	int	yt;
	int	zt;

	yt = y - fdf->map.width / 2;
	zt = z - fdf->map.height / 2;
	fdf->map.y0 = fdf->map.angle_y * (yt - zt) * fdf->map.zoom;
	fdf->map.z0 = fdf->map.angle_z * (yt + zt) * fdf->map.zoom;
	fdf->map.z0 -= fdf->map.values[z][y] * fdf->map.x_value;
	if (direction == 0)
	{
		fdf->map.y1 = fdf->map.angle_y * ((yt + 1) - zt) * fdf->map.zoom;
		fdf->map.z1 = fdf->map.angle_z * ((yt + 1) + zt) * fdf->map.zoom;
		fdf->map.z1 -= fdf->map.values[z][y + 1] * fdf->map.x_value;
	}
	if (direction == 1)
	{
		fdf->map.y1 = fdf->map.angle_y * (yt - (zt + 1)) * fdf->map.zoom;
		fdf->map.z1 = fdf->map.angle_z * (yt + (zt + 1)) * fdf->map.zoom;
		fdf->map.z1 -= fdf->map.values[z + 1][y] * fdf->map.x_value;
	}
	fdf->map.y0 += (WIN_WIDTH / 2) + fdf->map.coord_y;
	fdf->map.y1 += (WIN_WIDTH / 2) + fdf->map.coord_y;
	fdf->map.z0 += (WIN_HEIGHT / 2) + fdf->map.coord_z;
	fdf->map.z1 += (WIN_HEIGHT / 2) + fdf->map.coord_z;
	fdf_input_pixels_to_line(fdf);
}

int				fdf_draw(t_fdf *fdf)
{
	int	y;
	int	z;

	z = 0;
	fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	fdf->image.data = (int*)mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp, \
		&fdf->image.size, &fdf->image.endian);
	while (fdf->map.height > z)
	{
		y = 0;
		while (fdf->map.width > y)
		{
			fdf->map.y0 = y;
			if (fdf->map.width > y + 1)
				draw_lines(fdf, y, z, 0);
			if (fdf->map.height > z + 1)
				draw_lines(fdf, y, z, 1);
			y++;
		}
		fdf->map.z0 = z++;
	}
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	return (0);
}
