/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:36:16 by mcha              #+#    #+#             */
/*   Updated: 2021/11/18 01:08:44 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_digit(int n)
{
	int	cnt;
	int	digit;

	cnt = 0;
	digit = 1;
	if (n <= 0)
	{
		if (n == -2147483648)
			return (11);
		n *= -1;
		cnt++;
	}
	while (digit <= 1000000000)
	{
		if ((n / digit) > 0)
		{
			digit *= 10;
			cnt++;
		}
		else
			break ;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int			cnt;
	char		*buf;
	long long	tmp;

	cnt = ft_get_digit(n);
	buf = (char *)malloc((cnt + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (n < 0)
		tmp = (-1) * (long long)n;
	else
		tmp = (long long)n;
	buf[cnt--] = '\0';
	while (cnt >= 0)
	{
		buf[cnt--] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		buf[0] = '-';
	return (buf);
}
