/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <galfyn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:20:53 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/21 01:14:47 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rootList;

	rootList = malloc(sizeof(t_list));
	if (!rootList)
		return (NULL);
	rootList->content = content;
	rootList->next = NULL;
	return (rootList);
}
