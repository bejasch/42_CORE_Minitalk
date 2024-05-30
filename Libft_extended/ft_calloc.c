/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:00:44 by bschneid          #+#    #+#             */
/*   Updated: 2024/05/27 15:41:33 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*data;
	char	*copy;
	size_t	total;

	total = num * size;
	data = (char *)malloc(total);
	if (!data)
		return (0);
	copy = data;
	while (total--)
		*(copy++) = 0;
	return (data);
}
