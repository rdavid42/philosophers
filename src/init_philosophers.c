/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:52:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:52:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int					init_philosophers(t_core *c)
{
	int				i;

	i = -1;
	while (++i < PN)
	{
		c->p[i].life = MAX_LIFE;
		c->p[i].c = c;
		c->p[i].state = RESTING;
		c->p[i].i = i;
		c->p[i].stop = 0;
		c->p[i].sleep = 1;
	}
	return (1);
}
