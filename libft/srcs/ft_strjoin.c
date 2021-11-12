/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:19:28 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:19:30 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (str1 && str2)
	{
		if (!(ret = (char *)malloc(sizeof(char)
		* (ft_strlen(str1) + ft_strlen(str2) + 1))))
			return (NULL);
		while (*str1)
			ret[i++] = *str1++;
		while (*str2)
			ret[i++] = *str2++;
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
