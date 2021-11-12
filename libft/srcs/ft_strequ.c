/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:18:59 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:19:01 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *str1, char const *str2)
{
	size_t i;

	if (str1 && str2)
	{
		i = ft_strcmp(str1, str2);
		if (i != 0)
			return (0);
		else
			return (1);
	}
	return (0);
}
