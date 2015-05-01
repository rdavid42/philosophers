/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:52:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:52:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int					start_philosophers(t_core *c)
{
	int				i;

	i = -1;
	while (++i < PN)
	{
		if (pthread_create(&c->p[i].thread, NULL,
							start_philosopher, &c->p[i]) != 0)
			return (0);
		if (pthread_detach(c->p[i].thread) != 0)
			return (0);
	}
	return (1);
}
