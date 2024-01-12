/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:26:35 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/06 13:11:41 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_check_del(void *con, void *(*f)(void *), void (*d)(void *))
{
	void	*ptr;
	t_list	*result;

	ptr = f(con);
	result = ft_lstnew(ptr);
	if (!result)
	{
		if (ptr)
			d(ptr);
		return (0);
	}
	return (result);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (!f || !del || !lst)
		return (0);
	result = ft_check_del(lst->content, f, del);
	if (!result)
		return (0);
	temp = result;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_check_del(lst->content, f, del);
		if (temp->next == 0)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
