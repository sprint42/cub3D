/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:17:39 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 21:38:04 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

static char	**ft_free_garb(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	*tmp;
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!tab || !s)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			tmp = (char *)s;
			while (*s && *s != c)
				s++;
			tab[i] = ft_substr(tmp, 0, (s - tmp));
			if (!tab[i])
				return (ft_free_garb(tab));
			i++;
		}
		else
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
