/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multicheek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:56:13 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/25 15:37:01 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheeck_letters(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < (ft_strlen(argv[i])))
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		if (ft_strchr(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void	error(t_info *info)
{
	write(1, "Error\n", 6);
	free(info->list_a);
	free(info->list_b);
	free(info->list_two_a);
	free(info->list_two_b);
	free(info->temp_list);
	free(info);
	exit(0);
}

int	same_arg(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < info->nbr_list_a)
	{
		while (j < info->nbr_list_a)
		{
			if (info->list_a[i] == info->list_a[j])
			{
				error(info);
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	before_split(t_info *info, char *argv1)
{
	char	**spliter;
	int		i;
	int		nbr_arg;

	i = 0;
	nbr_arg = 0;
	spliter = ft_split(argv1, ' ');
	while (spliter[nbr_arg])
		nbr_arg++;
	info->list_a = malloc(sizeof(int) * (nbr_arg + 1));
	info->list_b = malloc(sizeof(int) * (nbr_arg + 1));
	info->temp_list = malloc(sizeof(int) * (nbr_arg + 1));
	info->list_two_a = malloc(sizeof(int) * (nbr_arg + 1));
	info->list_two_b = malloc(sizeof(int) * (nbr_arg + 1));
	info->nbr_list_a = nbr_arg;
	while (i < nbr_arg)
	{
		info->list_a[i] = ft_atoi(spliter[i]);
		i++;
	}
	while (nbr_arg > 0)
		free(spliter[--nbr_arg]);
	free(spliter);
}

void	big_argc(t_info *info, int argc, char **argv)
{
	int	i;
	int	nbr_argc;

	i = 0;
	nbr_argc = argc - 1;
	info->list_a = malloc(sizeof(int) * argc);
	info->list_b = malloc(sizeof(int) * argc);
	info->temp_list = malloc(sizeof(int) * argc);
	info->list_two_a = malloc(sizeof(int) * argc);
	info->list_two_b = malloc(sizeof(int) * argc);
	info->nbr_list_a = (argc - 1);
	while (i < nbr_argc)
	{
		info->list_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}
