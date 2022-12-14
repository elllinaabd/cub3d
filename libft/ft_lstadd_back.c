/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:53:21 by radan            #+#    #+#             */
/*   Updated: 2022/01/30 03:23:20 by radan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_elem;

	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else
		{
			last_elem = ft_lstlast(*alst);
			last_elem->next = new;
		}
	}
}
