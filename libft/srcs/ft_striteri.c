/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:48:37 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:48:38 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*fnc)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (str && *fnc)
	{
		while (str[i])
		{
			(fnc)(i, &str[i]);
			i++;
		}
	}
}
