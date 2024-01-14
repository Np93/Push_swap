/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:03:51 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 13:07:08 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	stock = info->list_a[0];
	while (i < info->nbr_list_a)
	{
		info->list_a[i] = info->list_a[i + 1];
		i++;
	}
	info->list_a[i - 1] = stock;
	write(1, "ra\n", 3);
}

void	two_ra(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	stock = info->list_two_a[0];
	while (i < info->nbr_two_a)
	{
		info->list_two_a[i] = info->list_two_a[i + 1];
		i++;
	}
	info->list_two_a[i - 1] = stock;
	ps_ra(info);
}

void	ps_rb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	stock = info->list_b[0];
	while (i < info->nbr_list_b)
	{
		info->list_b[i] = info->list_b[i + 1];
		i++;
	}
	info->list_b[i - 1] = stock;
	write(1, "rb\n", 3);
}

void	two_rb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	stock = info->list_two_b[0];
	while (i < info->nbr_two_b)
	{
		info->list_two_b[i] = info->list_two_b[i + 1];
		i++;
	}
	info->list_two_b[i - 1] = stock;
	ps_rb(info);
}
