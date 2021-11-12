/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <eparviai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:27:29 by eparviai          #+#    #+#             */
/*   Updated: 2020/06/29 00:01:22 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	output_error(int error_nbr)
{
	if (error_nbr == -1)
		ft_putstr("error - Malloc failed (why?)\n");
	if (error_nbr == -2)
		ft_putstr("error - Cant open designated fd!\n");
	if (error_nbr == -3)
		ft_putstr("Unable to validate file, (unsupported characters)\n");
	if (error_nbr == -4)
		ft_putstr("error\n");
	exit(-1);
}

void	fdf_usage(char *argv)
{
	ft_putstr("Usage:\n\t");
	ft_putstr(argv);
	ft_putstr(" 'fdf_file'\n");
	ft_putstr("Controls:\n");
	ft_putstr("\t\x1B[32m[Esc]				  \x1B[0m->"
	" \x1B[32mExit the program.\n");
	ft_putstr("\t[R]				  \x1B[0m->"
	"\x1B[32m Reset the map.\n");
	ft_putstr("\t[M]			   	  \x1B[0m->"
	"\x1B[32m Randomize colors.\n");
	ft_putstr("\t[+][-]			  	  \x1B[0m->"
	"\x1B[32m Zoom in and zoom out.\n");
	ft_putstr("\t[7][9]				  \x1B[0m->"
	"\x1B[32m Increase the scale\n");
	ft_putstr("\t[Kp Enter]			  \x1B[0m->"
	"\x1B[32m Switch between isometric and flat.\n");
	ft_putstr("\t[kp8][kp4][kp5][kp6]		  \x1B[0m->"
	"\x1B[32m Move the map.\n\x1B[0m");
}

void	reset_map(t_fdf *fdf)
{
	fdf->map.coord_z = 0;
	fdf->map.coord_y = 0;
	fdf->map.x_value = 1.00;
	fdf->map.angle_y = cos(M_PI / 3);
	fdf->map.angle_z = fdf->map.angle_y * sin(M_PI / 6);
	fdf->map.zoom = ceil((fdf->map.width > fdf->map.height)) \
	? (WIN_WIDTH / fdf->map.width) + MAX_ZOOM \
	: (WIN_HEIGHT / fdf->map.height) + MAX_ZOOM;
	fdf->map.isometric = 1;
	fdf->color = 0x1b3485;
}

int		fdf_keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ANSI_R)
		reset_map(fdf);
	else if (keycode == KEY_ANSI_M)
		randomize_color(fdf);
	else if (keycode == KEY_ANSI_KEYPAD5)
		fdf->map.coord_z += 5;
	else if (keycode == KEY_ANSI_KEYPAD8)
		fdf->map.coord_z -= 5;
	else if (keycode == KEY_ANSI_KEYPAD6)
		fdf->map.coord_y += 5;
	else if (keycode == KEY_ANSI_KEYPAD4)
		fdf->map.coord_y -= 5;
	else if (keycode == KEY_ANSI_KEYPADPLUS)
		fdf->map.zoom++;
	else if ((keycode == KEY_ANSI_KEYPADMINUS) && (fdf->map.zoom > MAX_ZOOM))
		fdf->map.zoom--;
	else if ((keycode == KEY_ANSI_KEYPAD7) && (fdf->map.x_value < MAX_X))
		fdf->map.x_value += 0.25;
	else if ((keycode == KEY_ANSI_KEYPAD9) && (fdf->map.x_value > -MAX_X))
		fdf->map.x_value -= 0.25;
	else if (keycode == KEY_ANSI_KEYPADENTER)
		fdf->map.angle_z *= (fdf->map.isometric++ % 2) ? 0.2 : 5;
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			output_error(-1);
		read_fdf(argv[1], fdf);
		ft_putstr("reading succesful\n");
		reset_map(fdf);
		ft_putstr("map reset\n");
		fdf->mlx.init = mlx_init();
		ft_putstr("initialization succesful\n");
		fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, \
					argv[1]);
		ft_putstr("window created \n");
		mlx_hook(fdf->mlx.win, 2, 3, fdf_keys, fdf);
		mlx_loop_hook(fdf->mlx.init, fdf_draw, fdf);
		mlx_loop(fdf->mlx.init);
	}
	else
		fdf_usage(argv[0]);
	return (0);
}
