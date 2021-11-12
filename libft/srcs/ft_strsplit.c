/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:19:47 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:19:49 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		allocate_array(char **data, const char *str, char c)
{
	int				read;
	const char		*end;
	size_t			length;

	read = 0;
	while (*str)
	{
		if ((*str != c && !read) && (read = 1))
		{
			end = ft_strchr(str, c);
			length = (end != NULL ? end - str : ft_strlen(str));
			*data++ = ft_strsub(str, 0, length);
		}
		else if (read && *str == c)
			read = 0;
		++str;
	}
}

static int		ft_words(char const *str, char c)
{
	int check;
	int word;

	check = 0;
	word = 0;
	while (*str)
	{
		if ((*str != c && check == 0) && (check = 1))
			word++;
		check = !(*str++ == c);
	}
	return (word);
}

char			**ft_strsplit(char const *str, char c)
{
	int		i1;
	int		i2;
	char	**array;

	i1 = 0;
	if (!str || !c)
		return (NULL);
	i2 = ft_words(str, c);
	if (!(array = (char**)malloc(sizeof(char*) * (i2 + 1))))
		return (NULL);
	array[i2] = NULL;
	allocate_array(array, str, c);
	return (array);
}
