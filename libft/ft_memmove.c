/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:15:02 by mcha              #+#    #+#             */
/*   Updated: 2021/11/18 20:29:28 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst != src && len)
	{
		if (dst < src)
		{
			new_dst = (unsigned char *)dst;
			new_src = (unsigned char *)src;
			while (len--)
				*new_dst++ = *new_src++;
		}
		else
		{
			new_dst = (unsigned char *)dst + (len - 1);
			new_src = (unsigned char *)src + (len - 1);
			while (len--)
				*new_dst-- = *new_src--;
		}
	}
	return (dst);
}
