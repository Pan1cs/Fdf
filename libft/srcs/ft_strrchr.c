/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:30:09 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/23 15:30:11 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)str;
	i = ft_strlen(str);
	if (chr == 0)
		return (ptr + i);
	while (i > 0)
	{
		i--;
		if (ptr[i] == chr)
			return (ptr + i);
	}
	return (NULL);
}
