/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:15:12 by mcha              #+#    #+#             */
/*   Updated: 2021/11/18 00:15:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*arr;
	unsigned char	src;
	size_t			i;

	arr = b;
	src = c;
	i = 0;
	while (i < len)
	{
		*arr = src;
		arr++;
		i++;
	}
	return (b);
}
