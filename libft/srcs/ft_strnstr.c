/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:30:22 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/23 15:30:27 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && l > 0)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && l - i > 0)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack + j);
		}
		l--;
		j++;
	}
	return (NULL);
}
