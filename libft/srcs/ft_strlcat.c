/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:29:40 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/23 15:29:42 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	str_i;
	size_t	i;
	size_t	ret;

	i = ft_strlen(src);
	str_i = ft_strlen(dest);
	if (str_i >= len)
		return (i + len);
	ret = str_i;
	while (ret < len - 1 && *src)
		dest[ret++] = *(src++);
	dest[ret] = '\0';
	return (i + str_i);
}
