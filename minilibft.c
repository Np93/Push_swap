/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:46:31 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 13:34:05 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				res;
	int				m;

	i = 0;
	m = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		m *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	res = res * m;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	ii;
	char			*ss;
	unsigned int	si;

	ii = 0;
	i = start;
	if (s == NULL)
		return (0);
	si = ft_strlen(s);
	if (si < start)
		len = 0;
	if (si - start < len)
		ss = malloc(si - start + 1 * sizeof(char));
	else
		ss = malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (0);
	while (s[i] != '\0' && i < len + start && start < si)
		ss[ii++] = s[i++];
	ss[ii] = '\0';
	return (ss);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
