/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:20:07 by clde-ber          #+#    #+#             */
/*   Updated: 2021/07/28 17:46:36 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_el(t_list *stack)
{
    int i;

    i = 0;
    while (stack->prec)
        stack = stack->prec;
    while (stack->next)
    {
        stack = stack->next;
        i++;
    }
    return (i + 1);
}

static int	conv_char_int(char str, int k)
{
	k *= 10;
	k += str - 48;
	return (k);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		k = conv_char_int(str[i], k);
		i++;
	}
	if (j % 2 != 0)
		return (k * -1);
	return (k);
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prec = NULL;
	return (new);
}

void    ft_lst_delone(t_list *el)
{
    el->value = 0;
    el->next = 0;
    el->prec = 0;
    free(el);
    el = NULL;
}

int init_stacks(t_list **stack_a, t_list **stack_b)
{
    *stack_a = NULL;
    *stack_b = NULL;
    return (0);
}

void    fill_list(t_list *stack_a, char *arg)
{
    stack_a = ft_lstnew(ft_atoi(arg));
}

void    ft_lst_addback(t_list **stack, t_list *el)
{
    while ((*stack)->next)
        (*stack) = (*stack)->next;
    (*stack)->next = el;
    el->prec = (*stack);
    *stack = (*stack)->next;
    el->next = NULL;
}

void    ft_lst_addfront(t_list **stack, t_list *el)
{
    while ((*stack)->prec)
        (*stack) = (*stack)->prec;
    el->next = (*stack);
    *stack = el;
    (*stack)->prec = 0;
}

void    go_to_first_el(t_list **stack)
{
    if (stack)
    {
        while ((*stack)->prec)
            (*stack) = (*stack)->prec;
    }
}

void    go_to_last_el(t_list **stack)
{
    if (stack)
    {
        while ((*stack)->next)
            (*stack) = (*stack)->next;
    }
}

void    free_stack(t_list *stack)
{
    t_list *tmp;

    tmp = NULL;
    if (stack)
    {
        while (stack->prec)
            stack = stack->prec;
        while (stack->next)
        {
            tmp = stack->next;
            ft_lst_delone(stack);
            stack = tmp;
        }
        ft_lst_delone(stack);
    }
}

void    print_no_details(t_list *stack_a, t_list *stack_b)
{
    if (stack_a)
    {
        while (stack_a->prec)
            stack_a = stack_a->prec;
        while (stack_a->next)
        {
            printf("stack a v %d\n", stack_a->value);
            stack_a = stack_a->next;
        }
        printf("stack a v %d\n", stack_a->value);
    }
    if (stack_b)
    {
        while (stack_b->prec)
            stack_b = stack_b->prec;
        while (stack_b->next)
        {
            printf("stack b v %d\n", stack_b->value);
            stack_b = stack_b->next;
        }
        printf("stack b v %d\n", stack_b->value);
    }
}

void    print_stack_a_a_b(t_list *stack_a, t_list *stack_b)
{
    if (stack_a)
    {
        while (stack_a->prec)
        stack_a = stack_a->prec;
        while (stack_a->next)
        {
            printf("stack a v %d\n", stack_a->value);
            printf("stack a %d\n", (int)stack_a);
            printf("stack a next %d\n", (int)stack_a->next);
            printf("stack a prec %d\n", (int)stack_a->prec);
            stack_a = stack_a->next;
        }
        printf("stack a v %d\n", stack_a->value);
        printf("stack a %d\n", (int)stack_a);
        printf("stack a next %d\n", (int)stack_a->next);
        printf("stack a prec %d\n", (int)stack_a->prec);
    }
    if (stack_b)
    {
        while (stack_b->prec)
            stack_b = stack_b->prec;
        while (stack_b->next)
        {
            printf("stack b v %d\n", stack_b->value);
            printf("stack b %d\n", (int)stack_b);
            printf("stack b next %d\n", (int)stack_b->next);
            printf("stack b prec %d\n", (int)stack_b->prec);
            stack_b = stack_b->next;
        }
        printf("stack b v %d\n", stack_b->value);
        printf("stack b %d\n", (int)stack_b);
        printf("stack b next %d\n", (int)stack_b->next);
        printf("stack b prec %d\n", (int)stack_b->prec);
    }
}

int is_max(int lst, int max)
{
    if (lst == max)
        return (1);
    return (0);
}

int find_max(t_list *max)
{
    int max_value;

    max_value = max->value;
    while (max->prec)
        max = max->prec;
    while (max->next)
    {
        if (max_value < max->value)
            max_value = max->value;
        max = max->next;
    }
    if (max_value < max->value)
        max_value = max->value;
    return (max_value);
}

int ra_o_rra(t_list *s_lst, int max)
{
    int i;
    
    i = 0;
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        if (s_lst->value == max)
            return (i);
        s_lst = s_lst->next;
        i++;
    }
    return (i);
}

void    push_swap(t_list **stack_a, t_list **stack_b, int nb)
{
    int x;
    int max;
    int j;

    x = 0;
    j = nb;
    max = find_max(*stack_a);
    while (j >= 0)
    {
        go_to_last_el(stack_a);
        if (is_max((*stack_a)->value, max) == 0)
            ft_sa_or_sb(*stack_a);
        go_to_last_el(stack_a);
        if ((is_max((*stack_a)->value, max)) || (x == j - 1))
        {
            ft_pb(stack_a, stack_b);
            max = find_max(*stack_a);
            go_to_last_el(stack_a);
            if (is_max((*stack_a)->value, max) == 0)
                ft_sa_or_sb(*stack_a);
            j -= 1;
            x = 0;
        }
        go_to_last_el(stack_a);
        if (is_max((*stack_a)->value, max) == 0 && x < j - 1)
        {
            if (ra_o_rra(*stack_a, max) > j / 2)
                ft_rra_or_rrb(*stack_a);
            else
                ft_ra_or_rb(*stack_a);
        }
        x++;
    }
    while (j < nb)
    {
        ft_pa(stack_a, stack_b);
        j++;
    }
    print_no_details(*stack_a, *stack_b);
}

int main(int ac, char **av)
{
    int i;
    t_list *stack_a;
    t_list *stack_b;
    t_list *tmp;

    i = 1;
    tmp = NULL;
    init_stacks(&stack_a, &stack_b);
    if (ac < 2)
        return (0);
    stack_a = ft_lstnew(ft_atoi(av[i]));
    i++;
    while (i < ac)
    {
        ft_lst_addback(&stack_a, ft_lstnew(ft_atoi(av[i])));
        i++;
    }
    print_no_details(stack_a, stack_b);
    printf("\n");
    push_swap(&stack_a, &stack_b, ac - 2);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}