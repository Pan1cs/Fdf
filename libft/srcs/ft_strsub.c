/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:19:20 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:19:22 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*sdup;
	size_t	i;

	if (!(str))
		return (NULL);
	if (!(sdup = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (str[start] != '\0' && i < len)
	{
		sdup[i] = str[start];
		i++;
		start++;
	}
	sdup[i] = '\0';
	return (sdup);
}
