/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:14:07 by lnieto-m          #+#    #+#             */
/*   Updated: 2015/12/09 20:19:33 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		del(NULL, 0);
		free(tmp);
		tmp = tmp->next;
	}
	*alst = NULL;
	free(*alst);
}
