/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:18:44 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:18:45 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*fnc)(unsigned int, char))
{
	size_t	i;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	if (!(ret = ft_strdup(str)))
		return (NULL);
	while (ret[i])
	{
		ret[i] = fnc(i, ret[i]);
		i++;
	}
	return (ret);
}
