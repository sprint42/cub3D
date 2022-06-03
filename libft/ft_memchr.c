/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:14:38 by mcha              #+#    #+#             */
/*   Updated: 2021/11/18 15:33:19 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;

	idx = 0;
	while (idx < n)
	{
		if (((unsigned char *)s)[idx] == (unsigned char)c)
			return ((void *)(s + idx));
		idx++;
	}
	return (0);
}
