/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:28:30 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/23 15:28:33 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*ret;

	ret = (unsigned char*)str;
	while (len--)
	{
		if (*ret == (unsigned char)c)
			return (ret);
		ret++;
	}
	return (NULL);
}
