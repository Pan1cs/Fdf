/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:18:28 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:18:29 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*fnc)(char))
{
	size_t	i;
	size_t	j;
	char	*ret;

	j = 0;
	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (!(ret = ft_strdup(str)))
		return (NULL);
	while (ret[j])
	{
		ret[j] = fnc(str[j]);
		j++;
	}
	return (ret);
}
