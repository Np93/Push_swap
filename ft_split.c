/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:50:03 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 12:50:54 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**foncfree(char **tab, int t_i)
{
	while (t_i > 0)
	{
		free(tab[t_i]);
		t_i--;
	}
	free(tab);
	return (NULL);
}

char	**manqdelign(char const *s, char c, char **tab)
{
	int	i;
	int	ii;
	int	t_i;

	i = 0;
	ii = 0;
	t_i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			ii = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[t_i] = ft_substr(s, ii, (i - ii) + 1);
			if (tab[t_i++] == NULL)
				return (foncfree(tab, t_i - 1));
		}
		i++;
	}
	tab[t_i] = NULL;
	return (tab);
}

int	compte(char const *s, char c)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			ii++;
		i++;
	}
	return (ii);
}

char	**ft_split(char const *s, char c)
{
	int		ii;
	char	**tab;

	if (s == NULL)
		return (0);
	ii = compte(s, c);
	tab = malloc((ii + 1) * sizeof(char *));
	if (tab == NULL)
		return (0);
	tab = manqdelign(s, c, tab);
	return (tab);
}
