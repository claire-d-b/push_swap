/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:39:47 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/10 10:51:45 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstnew(void *value)
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

void	ft_lst_delone(t_list *el)
{
	free_string(el->value);
	el->value = 0;
	el->next = 0;
	el->prec = 0;
	free(el);
	el = NULL;
}

void	ft_lst_addback(t_list **stack, t_list *el)
{
	if (!(*stack))
	{
		*stack = el;
		(*stack)->prec = 0;
		(*stack)->next = 0;
	}
	else
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = el;
		el->prec = (*stack);
		*stack = (*stack)->next;
		el->next = NULL;
	}
}

void	ft_lst_addfront(t_list **stack, t_list *el)
{
	while ((*stack)->prec)
		(*stack) = (*stack)->prec;
	if (!(*stack))
		*stack = el;
	el->next = (*stack);
	*stack = el;
	(*stack)->prec = 0;
}
