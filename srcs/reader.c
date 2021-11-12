/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <eparviai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:27:29 by eparviai          #+#    #+#             */
/*   Updated: 2020/06/29 00:01:22 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void			randomize_color(t_fdf *fdf)
{
	fdf->color = rand();
}

static int		get_numbers(char *line)
{
	int		len;

	len = 0;
	if (!ft_isdigit(*line) && *line != '-')
		output_error(-3);
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			len++;
			while (ft_isdigit(*line))
				line++;
			if (*line == ',')
				while (*line != ' ' && *line)
					line++;
		}
		if (*line)
			line++;
	}
	return (len);
}

static int		get_rows(t_fdf *fdf, char *argv)
{
	int		fd;
	int		len;
	int		rows;
	int		cols;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) < 0)
		output_error(-2);
	rows = 0;
	cols = 0;
	len = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '\0')
			break ;
		if ((len = get_numbers(line)) > cols)
			cols = len;
		rows++;
		free(line);
	}
	if (close(fd) < 0)
		output_error(-4);
	if (!(fdf->map.width = cols))
		output_error(-3);
	return (rows);
}

static	void	fetch_z(t_fdf *fdf, int y, int z, char *line)
{
	int		i;
	char	**split;

	if ((split = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (split[i] && (y != fdf->map.width))
		{
			fdf->map.values[z][y] = ft_atoi(split[i]);
			y += 1;
			free(split[i]);
			i++;
		}
		free(split);
	}
}

void			read_fdf(char *argv, t_fdf *fdf)
{
	int		z;
	int		y;
	char	*line;
	int		fd;

	y = 0;
	z = 0;
	fdf->map.height = get_rows(fdf, argv);
	if ((fd = open(argv, O_RDONLY)) < 0)
		output_error(-2);
	if (!(fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height)))
		output_error(-1);
	while (get_next_line(fd, &line) == 1 && z != fdf->map.height)
	{
		if (!(fdf->map.values[z] = (int *)malloc(sizeof(int) * fdf->map.width)))
			output_error(-1);
		fetch_z(fdf, y, z, line);
		y = 0;
		z++;
		free(line);
	}
	if (close(fd) < 0)
		output_error(-4);
}
