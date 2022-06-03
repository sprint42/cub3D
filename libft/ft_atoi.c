/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:13:10 by mcha              #+#    #+#             */
/*   Updated: 2021/11/19 10:53:36 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			cnt_sign;
	long long	result;

	sign = 1;
	cnt_sign = 0;
	result = 0;
	while (ft_isspace(*str))
		str++;
	while (ft_issign(*str))
	{
		if (*str++ == '-')
			sign *= -1;
		if (++cnt_sign > 1)
			return (0);
	}
	while (ft_isnum(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((int)result * sign);
}
