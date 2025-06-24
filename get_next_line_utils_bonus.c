/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhara <nhara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:45:01 by nhara             #+#    #+#             */
/*   Updated: 2024/12/19 14:25:47 by nhara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	if (s2 != NULL)
		s2_len = ft_strlen(s2);
	else
		s2_len = 0;
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1)
		ft_strlcpy(str, s1, s1_len + 1);
	else
		str[0] = '\0';
	if (s2)
		ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	if (!s)
		return (NULL);
	copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}
