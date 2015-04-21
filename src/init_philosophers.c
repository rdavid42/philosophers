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

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "core.h"

void				*start_philosopher(void *pa)
{
	t_philosopher	*s = (t_philosopher *)pa;

	(void)lp;
	(void)rp;
	dprintf(2, "%d, %d, %d\n", s->i, lp->i, rp->i);
	while (1)
	{
		usleep(MS(1));
	}
	return (NULL);
}

void				release_sticks(void)
{

}

void				release_philosophers(void)
{

}

int					init_sticks(t_core *c)
{
	int				i;

	i = 0;
	while (i < PN)
	{
		c->s[i].state = 0;
		if (pthread_mutex_init(&c->s[i].mutex, NULL) != 0)
			return (0);
		++i;
	}
}

int					init_philosophers(t_core *c)
{
	int				i;
	int				err;

	i = 0;
	while (i < PN)
	{
		c->p[i].state = RESTING;
		c->p[i].left_stick = &c->s[i];
		c->p[i].right_stick = NULL;
/*		if (pthread_mutex_init(&c->p[i].mutex, NULL) != 0)
			return (0);*/
		if ((err = pthread_create(&c->p[i].thread, NULL,
									start_philosopher, &c->p[i])) != 0)
			return (0);
		++i;
	}
	return (1);
}
