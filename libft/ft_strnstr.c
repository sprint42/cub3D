/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:16:01 by mcha              #+#    #+#             */
/*   Updated: 2021/11/18 00:16:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	t_len;

	if (*needle == '\0')
		return ((char *)haystack);
	t_len = ft_strlen(needle);
	while (*haystack && (len-- >= t_len))
	{
		if (*haystack == *needle)
		{
			if (ft_memcmp(haystack, needle, t_len) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
