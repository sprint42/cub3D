/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_leak.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:55:35 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 16:51:48 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_leak(char const *s1, char const *s2)
{
	char		*buf;
	size_t		len_s1;
	size_t		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	buf = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s1, len_s1 + 1);
	ft_strlcpy(buf + len_s1, s2, len_s2 + 1);
	if (s1)
		free((void *)s1);
	if (s2)
		free((void *)s2);
	return (buf);
}
