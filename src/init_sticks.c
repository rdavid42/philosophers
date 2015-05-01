/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sticks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:52:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:52:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int					init_sticks(t_core *c)
{
	int				i;

	i = -1;
	while (++i < PN)
	{
		c->s[i].owner = -1;
		if (pthread_mutex_init(&c->s[i].mutex, NULL) != 0)
			return (0);
	}
	return (1);
}
