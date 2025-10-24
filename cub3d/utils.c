/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Simple string length function
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Simple string copy function
char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Simple integer to string function
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		temp;

	temp = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = (n < 0) ? 2 : 1;
	temp = (temp < 0) ? -temp : temp;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[--len] = '\0';
	temp = (n < 0) ? -n : n;
	while (temp > 0)
	{
		str[--len] = (temp % 10) + '0';
		temp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// Simple implementation of ft_strlcpy
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}