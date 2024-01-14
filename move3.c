/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:15:12 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 13:19:50 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->nbr_list_a > 1)
	{
		stock = info->list_a[i];
		info->list_a[i] = info->list_a[i + 1];
		info->list_a[i + 1] = stock;
	}
	write(1, "sa\n", 3);
}

void	two_sa(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->nbr_two_a > 1)
	{
		stock = info->list_two_a[i];
		info->list_two_a[i] = info->list_two_a[i + 1];
		info->list_two_a[i + 1] = stock;
	}
	ps_sa(info);
}

void	ps_sb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->nbr_list_b > 1)
	{
		stock = info->list_b[i];
		info->list_b[i] = info->list_b[i + 1];
		info->list_b[i + 1] = stock;
	}
	write(1, "sb\n", 3);
}

void	two_sb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->nbr_two_b > 1)
	{
		stock = info->list_two_b[i];
		info->list_two_b[i] = info->list_two_b[i + 1];
		info->list_two_b[i + 1] = stock;
	}
	ps_sb(info);
}

void	two_ss(t_info *info)
{
	two_sa(info);
	two_sb(info);
}
