/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:49:53 by eparviai          #+#    #+#             */
/*   Updated: 2019/12/09 17:49:54 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_chr(const char *str, char c)
{
	size_t len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	return (len);
}
