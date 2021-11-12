/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:19:53 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:19:54 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	char	*ret;
	int		tmp;
	int		sign;
	int		i;

	tmp = nb;
	i = 1;
	sign = nb < 0;
	while (tmp /= 10)
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1 + sign))))
		return (NULL);
	if (sign)
		*ret++ = '-';
	ret += i;
	*ret-- = '\0';
	if (nb == 0)
		*ret-- = 48;
	while (nb)
	{
		*ret-- = (nb % 10) * (sign ? -1 : 1) + 48;
		nb /= 10;
	}
	return (ret + 1 - sign);
}
