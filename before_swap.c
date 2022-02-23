/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:27:31 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 13:46:43 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_info *info)
{
	int	small;
	int	i;
	int	small_pos;

	small = 2147483647;
	i = 0;
	small_pos = 0;
	while (i < info->nbr_list_a)
	{
		if (info->temp_list[i] < small)
		{
			small = info->temp_list[i];
			small_pos = i;
		}
		i++;
	}
	info->temp_list[small_pos] = 2147483647;
	return (small_pos);
}

void	forcing(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_list_a)
	{
		if (info->temp_list[i] != -2147483648)
			info->temp_list[i] = ((info->temp_list[i]) - 1);
		i++;
	}
}

void	list_two(t_info *info)
{
	int	i;
	int	small_pos;

	i = -1;
	while (i++ < info->nbr_list_a)
	{
		info->list_two_a[i] = info->list_a[i];
		info->temp_list[i] = info->list_a[i];
	}
	info->nbr_two_a = info->nbr_list_a;
	info->nbr_two_b = info->nbr_list_b;
	i = 0;
	while (i < info->nbr_list_a)
	{
		if (info->list_a[i] == 2147483647)
			forcing(info);
		i++;
	}
	i = 0;
	while (info->nbr_two_a > 0)
	{
		small_pos = find_smallest(info);
		info->nbr_two_a--;
		info->list_two_a[small_pos] = ++i;
	}
}

int	check_order(t_info *info)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (count < info->nbr_two_a)
	{
		if (info->list_two_a[count] == i)
			i++;
		count++;
	}
	if ((i - 1) == count)
		return (0);
	return (1);
}

int	before_swap(t_info *info)
{
	info->nbr_list_b = 0;
	list_two(info);
	info->nbr_two_a = info->nbr_list_a;
	if (check_order(info) == 0)
		return (0);
	info->chunk_size = 20;
	info->chunk_done = 1;
	if (info->nbr_list_a == 2)
		algo_two(info);
	if (info->nbr_list_a == 3)
		algo_three(info);
	if (info->nbr_list_a == 4)
		algo_four(info);
	if (info->nbr_list_a == 5)
		algo_five(info);
	if (info->nbr_list_a > 5)
		algo_five_hundred(info);
	return (0);
}
