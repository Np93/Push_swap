/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:07:15 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 13:15:02 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rrb(t_info *info)
{
	int	stock;
	int	i;

	i = info->nbr_list_b - 1;
	stock = info->list_b[i];
	while (i > 0)
	{
		info->list_b[i] = info->list_b[i - 1];
		i--;
	}
	info->list_b[0] = stock;
	write(1, "rrb\n", 4);
}

void	two_rrb(t_info *info)
{
	int	stock;
	int	i;

	i = info->nbr_two_b - 1;
	stock = info->list_two_b[i];
	while (i > 0)
	{
		info->list_two_b[i] = info->list_two_b[i - 1];
		i--;
	}
	info->list_two_b[0] = stock;
	ps_rrb(info);
}

void	ps_rra(t_info *info)
{
	int	stock;
	int	i;

	i = info->nbr_list_a - 1;
	stock = info->list_a[i];
	while (i > 0)
	{
		info->list_a[i] = info->list_a[i - 1];
		i--;
	}
	info->list_a[0] = stock;
	write(1, "rra\n", 4);
}

void	two_rra(t_info *info)
{
	int	stock;
	int	i;

	i = info->nbr_two_a - 1;
	stock = info->list_two_a[i];
	while (i > 0)
	{
		info->list_two_a[i] = info->list_two_a[i - 1];
		i--;
	}
	info->list_two_a[0] = stock;
	ps_rra(info);
}
