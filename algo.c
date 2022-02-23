/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:20:49 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 13:43:58 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	try_push_next(t_info *info, int jump)
{
	if (info->list_two_b[0] == info->list_two_b[info->nbr_two_b - 1] && !jump)
	{
		two_pa(info);
		return (1);
	}
	return (0);
}

int	rotate_in_b(t_info *info)
{
	int	count;
	int	jump;
	int	i;
	int	stack_b;

	i = 0;
	count = 0;
	jump = 0;
	stack_b = info->nbr_two_b;
	while (info->list_two_b[i] != info->nbr_two_b && ++count)
		i++;
	while (info->list_two_b[0] != stack_b)
	{
		if (try_push_next(info, jump) == 0)
		{
			if (count > stack_b / 2)
				two_rrb(info);
			else
				two_rb(info);
		}
		else
			jump = 1;
	}
	return (jump);
}

static void	push_in_b(t_info *info)
{
	int	count;

	count = 0;
	while (info->nbr_two_a > 0)
	{
		if (info->list_two_a[0] <= (info->chunk_size * info->chunk_done))
		{
			two_pb(info);
			if (info->list_two_b[0]
				< info->chunk_size * info->chunk_done - (info->chunk_size / 2))
				two_rb(info);
			if (info->list_two_b[0] < info->list_two_b[1])
				two_sb(info);
			count++;
		}
		else
			two_ra(info);
		if (count >= info->chunk_size * info->chunk_done)
			info->chunk_done = info->chunk_done + 1;
	}
}

static void	push_a_in_order(t_info *info)
{
	while (info->nbr_two_b > 0)
	{
		if (rotate_in_b(info))
		{
			two_pa(info);
			if (info->nbr_two_b > 1
				&& info->list_two_b[0] < info->list_two_b[1])
				two_ss(info);
			else
				two_sa(info);
		}
		else
			two_pa(info);
	}
}

void	algo_five_hundred(t_info *info)
{
	if (info->nbr_two_a <= 500)
		info->chunk_size = info->nbr_two_a / 10;
	if (info->nbr_two_a <= 40)
		info->chunk_size = info->nbr_two_a / 2;
	if (info->nbr_two_a <= 100)
		info->chunk_size = 20;
	push_in_b(info);
	while (info->nbr_two_b > 0)
		push_a_in_order(info);
}
