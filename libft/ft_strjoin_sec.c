/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:44:11 by mcha              #+#    #+#             */
/*   Updated: 2022/06/03 20:44:17 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sec(char *s1, char const *s2)
{
	char	*str;
	int		f_idx;
	int		s_idx;

	if (!s1)
		s1 = ft_strdup("");
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	f_idx = 0;
	while (s1[f_idx])
	{
		str[f_idx] = s1[f_idx];
		f_idx++;
	}
	s_idx = 0;
	while (s2[s_idx])
		str[f_idx++] = s2[s_idx++];
	str[f_idx] = '\0';
	free(s1);
	return (str);
}
