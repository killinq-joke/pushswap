/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:53:05 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/29 11:08:08 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef struct s_cell		t_cell;
typedef struct s_scell		t_scell;
typedef struct s_group_node	t_group_node;

typedef struct s_group_node
{
	int				pivotHigh;
	int				pivotLow;
	int				group_len;
	t_group_node	*next;
}				t_group_node;

typedef struct s_group
{
	t_group_node	*groupA;
	t_group_node	*groupB;
}				t_group;

typedef struct s_cell {
	int		v;
	t_cell	*n;
	int		id;
}				t_cell;
typedef struct s_scell {
	char	*str;
	t_scell	*n;
}				t_scell;

typedef struct s_piles {
	t_cell	*pileA;
	t_cell	*pileB;
	t_cell	*expectedpileA;
	int		expectedlen;
	t_scell	*results;
}				t_piles;

int				sortA(t_piles *piles);
void			print_tab(t_piles *piles);
void			push_a(t_piles *piles);
void			push_b(t_piles *piles);
void			rotate_a(t_piles *piles, int isRR);
void			rotate_b(t_piles *piles, int isRR);
void			rr(t_piles *piles);
void			ss(t_piles *piles);
void			swap_a(t_piles *piles, int isSS);
void			swap_b(t_piles *piles, int isSS);
void			swap(t_piles *piles, char pilename);
int				check_error(char *arg);
void			free_piles(t_piles *piles);
void			push_tailA(t_piles *piles, t_cell *new);
t_cell			*init_cell(int value);
int				pars_ints(t_piles *piles, char **split);
int				parser(t_piles *piles, int ac, char **av);
int				check_dup(t_piles *piles);
int				check_error(char *arg);
int				error_print(t_piles *piles, char **split);
void			reverse_ra(t_piles *piles, int isRRR);
void			reverse_rb(t_piles *piles, int isRRR);
void			rrr(t_piles *piles);
void			print_pileA(t_piles *piles);
void			reverse_print_pileA(t_piles *piles);
void			print_pileB(t_piles *piles);
void			print_tabs(t_piles *piles);
void			print_groups(t_group *groups);
t_cell			*pilecpy(t_cell *pile);
int				pilelen(t_cell *pile);
t_cell			*pilesort(t_cell *pile);
int				pivotfinder(t_cell *pile);
void			trivotfinder(t_cell *pile, t_group_node *group);
t_group_node	*init_group(int group_len);
void			addgrouphead(t_group_node **head, t_group_node *new);
void			sortA1(t_piles *piles, int i);
void			sortB1(t_piles *piles, int median, int numofsup, int i);
int				sortA(t_piles *piles);
int				sortB(t_piles *piles);
int				pilesupnum(t_cell *pile, int nb);
int				pileinfnum(t_cell *pile, int nb);
int				partissorted(t_piles *piles, t_cell *pile);
int				isrevsorted(t_cell *pile);
int				pileidsorted(t_cell *pile);
void			printpile(t_cell *pile);
t_cell			*groupcpy(t_cell *pile);
int				grouplen(t_cell *pile);
int				printid(t_piles *piles);
void			push(t_piles *piles, char pilename);
void			free_pile(t_cell *pile);
int				issorted(t_piles *piles);
t_scell			*init_scell(char *str);
void			addtab(t_piles *piles, char *str);
void			sort3A(t_piles *piles);
void			free_res(t_scell *res);
void			sortlow(t_piles *piles);
int				sort(t_piles *piles);
void			sort3B(t_piles *piles);
void			sort3(t_piles *piles);
int				distanceinf(t_piles *piles, int median);
int				sortA2(t_piles *piles, int i, int median, int rrnum);

#endif
