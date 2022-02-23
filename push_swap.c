/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:10:04 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 14:19:17 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min(char **splity)
{
	int		i;

	i = 0;
	while (splity[i])
	{
		if (ft_strlen(splity[i]) == ft_strlen("-2147483648"))
		{
			if (ft_strcmp(splity[i], "-2147483648") > 0)
				return (0);
		}
		else if (ft_strlen(splity[i]) > ft_strlen("-2147483648"))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_max(char **splity)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (splity[i])
	{
		if (splity[i][0] != '-')
		{
			if (ft_strlen(splity[i]) == ft_strlen("2147483647"))
			{
				if (ft_strcmp(splity[i], "2147483647") > 0)
					return (0);
			}
			else if (ft_strlen(splity[i]) > ft_strlen("2147483647"))
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	error_min_max(t_info *info, char **splity)
{
	free(splity);
	error(info);
	return (0);
}

int	min_max_int(t_info *info, int argc, char **argv)
{
	char	**splity;
	int		i;

	i = 0;
	if (argc == 1)
		splity = NULL;
	if (argc == 2)
	{
		splity = ft_split(argv[1], ' ');
		if (check_max(splity) == 0 || check_min(splity) == 0)
			error_min_max(info, splity);
	}
	if (argc > 2)
	{
		splity = malloc(sizeof(char) * argc);
		while (i < info->nbr_list_a)
		{
			splity[i] = argv[i + 1];
			i++;
		}
		if (check_max(splity) == 0 || check_min(splity) == 0)
			error_min_max(info, splity);
	}
	free(splity);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	info = malloc(sizeof(t_info));
	i = 0;
	if (argc == 1)
		return (0);
	if (cheeck_letters(argc, argv) == 0)
		return (0);
	if (argc == 2)
		before_split(info, argv[1]);
	if (argc > 2)
		big_argc(info, argc, argv);
	if (same_arg(info) == 0)
		return (0);
	if (min_max_int(info, argc, argv) == 0)
		return (0);
	before_swap(info);
	all_is_free(info);
	return (0);
}
