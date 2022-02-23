/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:13:47 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/23 13:40:48 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_info
{
	int	*list_a;
	int	*list_b;
	int	*list_two_a;
	int	*list_two_b;
	int	*temp_list;
	int	nbr_two_a;
	int	nbr_two_b;
	int	nbr_list_a;
	int	nbr_list_b;
	int	chunk_done;
	int	nbr_done;
	int	chunk_size;
}	t_info;

int		main(int argc, char **argv);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *str1, const char *str2);
char	**ft_split(char const *s, char c);
int		cheeck_letters(int argc, char **argv);
void	error(t_info *info);
int		same_arg(t_info *info);
void	before_split(t_info *info, char *argv1);
void	big_argc(t_info *info, int argc, char **argv);
void	two_pa(t_info *info);
void	two_pb(t_info *info);
void	two_ra(t_info *info);
void	two_rb(t_info *info);
void	two_rra(t_info *info);
void	two_rrb(t_info *info);
void	two_sa(t_info *info);
void	two_sb(t_info *info);
void	two_ss(t_info *info);
void	algo_five_hundred(t_info *info);
void	algo_two(t_info *info);
void	algo_three(t_info *info);
void	algo_four(t_info *info);
void	algo_five(t_info *info);
int		before_swap(t_info *info);
void	all_is_free(t_info *info);

#endif
