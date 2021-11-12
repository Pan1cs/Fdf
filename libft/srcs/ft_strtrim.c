/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:19:40 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:19:41 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		c;
	int		i;
	int		j;
	char	*ret;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	c = ft_strlen(s) - 1;
	if (i > c)
	{
		if (!(ret = ft_memalloc(1)))
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	while (s[c] == ' ' || s[c] == '\t' || s[c] == '\n' || s[c] == '\0')
		c--;
	ret = ft_strsub(s, i, c - i + 1);
	return (ret);
}
