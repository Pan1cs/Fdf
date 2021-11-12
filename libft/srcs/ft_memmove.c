/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:28:22 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/23 15:28:25 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t len)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	i = 0;
	if (len > 0 && (str1 || str2))
	{
		if (str1 > str2)
		{
			while (i++ < len)
				dest[len - i] = src[len - i];
		}
		else
		{
			while (len--)
			{
				dest[i] = src[i];
				i++;
			}
		}
	}
	return (dest);
}
