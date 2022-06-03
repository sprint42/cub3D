/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:38:56 by mcha              #+#    #+#             */
/*   Updated: 2021/11/16 21:24:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*buf;
	size_t		len_s1;
	size_t		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	buf = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s1, len_s1 + 1);
	ft_strlcpy(buf + len_s1, s2, len_s2 + 1);
	return (buf);
}
