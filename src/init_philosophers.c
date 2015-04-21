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

void				unlock_sticks(t_philosopher *p)
{
	if (p->left_locked)
	{
		pthread_mutex_unlock(&p->c->s[p->i]);
		p->left_locked = 0;
	}
	if (p->right_locked)
	{
		pthread_mutex_unlock(&p->c->s[(p->i + 1) % PN]);
		p->right_locked = 0;
	}
}

void				*start_philosopher(void *pa)
{
	t_philosopher	*s = (t_philosopher *)pa;

	while (!s->stop)
	{
		if (s->state == RESTING)
		{
			unlock_sticks();
			usleep(MS(REST_T));
		}
		
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

	i = 0;
	while (i < PN)
	{
		c->p[i].life = MAX_LIFE;
		c->p[i].c = c;
		c->p[i].state = RESTING;
		c->p[i].left_locked = 0;
		c->p[i].right_locked = 0;
		c->p[i].i = i;
		c->p[i].is_locked = 0;
		if (pthread_mutex_init(&c->p[i].mutex, NULL) != 0)
			return (0);
		c->p[i].stop = 0;
		if (pthread_create(&c->p[i].thread, NULL,
							start_philosopher, &c->p[i]) != 0)
			return (0);
		++i;
	}
	return (1);
}
