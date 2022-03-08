/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:01:11 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 13:03:38 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->nbr_list_b > 0)
	{
		stock = info->list_b[i];
		while (i < (info->nbr_list_b - 1))
		{
			info->list_b[i] = info->list_b[i + 1];
			i++;
		}
		i = info->nbr_list_a + 1;
		while (i > 0 )
		{
			--i;
			info->list_a[i + 1] = info->list_a[i];
		}
		info->list_a[0] = stock;
		info->nbr_list_b--;
		info->nbr_list_a++;
		write(1, "pa\n", 3);
	}
}

void	two_pa(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->nbr_two_b > 0)
	{
		stock = info->list_two_b[i];
		while (i < (info->nbr_two_b - 1))
		{
			info->list_two_b[i] = info->list_two_b[i + 1];
			i++;
		}
		i = info->nbr_two_a + 1;
		while (i > 0 )
		{
			--i;
			info->list_two_a[i + 1] = info->list_two_a[i];
		}
		info->list_two_a[0] = stock;
		info->nbr_two_b--;
		info->nbr_two_a++;
		ps_pa(info);
	}
}

void	ps_pb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->nbr_list_a > 0)
	{
		stock = info->list_a[i];
		while (i < (info->nbr_list_a - 1))
		{
			info->list_a[i] = info->list_a[i + 1];
			i++;
		}
		i = info->nbr_list_b + 1;
		while (i > 0)
		{
			--i;
			info->list_b[i + 1] = info->list_b[i];
		}
		info->list_b[0] = stock;
		info->nbr_list_a--;
		info->nbr_list_b++;
		write(1, "pb\n", 3);
	}
}

void	two_pb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->nbr_two_a > 0)
	{
		stock = info->list_two_a[i];
		while (i < (info->nbr_two_a - 1))
		{
			info->list_two_a[i] = info->list_two_a[i + 1];
			i++;
		}
		i = info->nbr_two_b + 1;
		while (i > 0)
		{
			--i;
			info->list_two_b[i + 1] = info->list_two_b[i];
		}
		info->list_two_b[0] = stock;
		info->nbr_two_a--;
		info->nbr_two_b++;
		ps_pb(info);
	}
}
