/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algosmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:23:11 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 14:12:07 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_two(t_info *info)
{
	two_sa(info);
}

void	algo_three(t_info *info)
{
	if (info->list_two_a[0] == 1)
	{
		if (info->list_two_a[1] != 2 || info->list_two_a[2] != 3)
		{
			two_sa(info);
			two_ra(info);
		}
	}
	if (info->list_two_a[0] == 2 && info->list_two_a[1] == 1)
		two_sa(info);
	if (info->list_two_a[0] == 2 && info->list_two_a[2] == 1)
		two_rra(info);
	if (info->list_two_a[0] == 3 && info->list_two_a[2] == 1)
	{
		two_ra(info);
		two_sa(info);
	}
	if (info->list_two_a[0] == 3 && info->list_two_a[1] == 1)
		two_ra(info);
}

void	algo_four(t_info *info)
{
	if (info->list_two_a[3] == 4)
		two_rra(info);
	while (info->nbr_two_b < 1)
	{
		while (info->list_two_a[0] != 4)
		{
			two_ra(info);
		}
		two_pb(info);
	}
	algo_three(info);
	two_pa(info);
	two_ra(info);
}

void	algo_five(t_info *info)
{
	if (info->list_two_a[4] == 4 || info->list_two_a[4] == 5)
		two_rra(info);
	while (info->nbr_two_b < 2)
	{
		while ((info->list_two_a[0] != 4) && (info->list_two_a[0] != 5))
			two_ra(info);
		two_pb(info);
	}
	algo_three(info);
	if (info->list_two_b[0] == 4)
	{
		two_pa(info);
		two_ra(info);
		two_pa(info);
		two_ra(info);
	}
	else
	{
		two_pa(info);
		two_pa(info);
		two_ra(info);
		two_ra(info);
	}
}

void	all_is_free(t_info *info)
{
	free(info->list_a);
	free(info->list_b);
	free(info->list_two_a);
	free(info->list_two_b);
	free(info->temp_list);
	free(info);
}
