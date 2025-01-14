/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:54:13 by bschneid          #+#    #+#             */
/*   Updated: 2024/04/22 15:52:54 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*str;
	unsigned char	*from;

	if (!dest && !src)
		return (0);
	str = dest;
	from = (unsigned char *)src;
	while (count--)
		*(str++) = *(from++);
	return (dest);
}
