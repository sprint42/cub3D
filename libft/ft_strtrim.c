/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:28:37 by mcha              #+#    #+#             */
/*   Updated: 2022/05/31 20:09:22 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimfind(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	if (*set == '\0' && *set == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (!ft_trimfind(set, *s1))
			break ;
		s1++;
	}
	i = ft_strlen(s1);
	while (i)
	{
		if (!ft_trimfind(set, s1[i]))
			break ;
		i--;
	}
	return (ft_substr(s1, 0, i + 1));
}
