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

void				unlock_sticks(t_philosopher *p, t_stick *s[2])
{
	if (p->left_locked)
	{
		pthread_mutex_unlock(&s[0]->mutex);
		p->left_locked = 0;
	}
	if (p->right_locked)
	{
		pthread_mutex_unlock(&s[1]->mutex);
		p->right_locked = 0;
	}
}

void				try_lock_sticks(t_philosopher *p, t_stick *s[2])
{
	if (!p->left_locked && !pthread_mutex_trylock(&s[0]->mutex))
		p->left_locked = 1;
	if (!p->right_locked && !pthread_mutex_trylock(&s[1]->mutex))
		p->right_locked = 1;
}

void				lock_sticks(t_philosopher *p, t_stick *s[2])
{
	if (!pthread_mutex_lock(&s[0]->mutex))
		p->left_locked = 1;
	if (!pthread_mutex_lock(&s[1]->mutex))
		p->right_locked = 1;
}

void				request_sticks(t_philosopher *p, t_stick *s[2],
									t_philosopher *n[2])
{
	n[0]->request = REQUEST_STICK;
	n[1]->request = REQUEST_STICK;
	lock_sticks(p, s);
	p->state = EATING;
}

void				philosopher_try_action(t_philosopher *p, t_stick *s[2],
											t_philosopher *n[2])
{
	try_lock_sticks(p, s);
	if (p->left_locked && p->right_locked)
		p->state = EATING;
	else
	{
		if (n[0]->state == THINKING && n[1]->state == THINKING)
			request_sticks(p, s, n);
		else if (p->right_locked)
		{
			if (n[0]->state == THINKING)
			{
				n[0]->request = REQUEST_STICK;
				pthread_mutex_lock(&s[0]->mutex);
				p->left_locked = 1;
				p->state = EATING;
			}
			else if (n[0]->state == EATING)
				p->state = THINKING;
		}
		else if (p->left_locked)
		{
			if (n[1]->state == THINKING)
			{
				n[1]->request = REQUEST_STICK;
				pthread_mutex_lock(&s[1]->mutex);
				p->right_locked = 1;
				p->state = EATING;
			}
			else if (n[1]->state == EATING)
				p->state = THINKING;
		}
		else
			p->state = RESTING;
	}
}

void				philosopher_rest(t_philosopher *p, t_stick *s[2],
										t_philosopher *n[2])
{
	usleep(MS(REST_T));
	philosopher_try_action(p, s, n);
}

void				philosopher_eat(t_philosopher *p, t_stick *s[2],
									t_philosopher *n[2])
{
	(void)n;
	usleep(MS(EAT_T));
	p->life = MAX_LIFE;
	unlock_sticks(p, s);
	p->state = RESTING;
}

void				philosopher_think(t_philosopher *p, t_stick *s[2],
										t_philosopher *n[2])
{
	size_t			elapsed;

	(void)n;
	elapsed = 0;
	if (p->request == REQUEST_STICK)
	{
		unlock_sticks(p, s);
		p->state = RESTING;
		return ;
	}
	while (elapsed < MS(THINK_T))
	{
		usleep(MW);
		if (p->request == REQUEST_STICK)
		{
			unlock_sticks(p, s);
			p->state = RESTING;
			return ;
		}
		elapsed += MW;
	}
	philosopher_try_action(p, s, n);
}

void				*start_philosopher(void *pa)
{
	t_philosopher	*p = (t_philosopher *)pa;
	t_stick			*s[2];
	t_philosopher	*n[2];

	s[0] = &p->c->s[p->i];
	s[1] = &p->c->s[(p->i + 1) % PN];
	n[0] = &p->c->p[(p->i - 1) < 0 ? PN - 1 : (p->i - 1)];
	n[1] = &p->c->p[(p->i + 1) % PN];
	while (!p->stop && p->life > 0)
	{
		if (p->state == RESTING)
			philosopher_rest(p, s, n);
		else if (p->state == EATING)
			philosopher_eat(p, s, n);
		else if (p->state == THINKING)
			philosopher_think(p, s, n);
	}
	unlock_sticks(p, s);
	return (NULL);
}

int					release_sticks(t_core *c)
{
	int				i;

	i = -1;
	while (++i < PN)
	{
		if (pthread_mutex_destroy(&c->s[i].mutex) != 0)
			return (0);
	}
	return (1);
}

int					init_sticks(t_core *c)
{
	int				i;

	i = -1;
	while (++i < PN)
	{
		if (pthread_mutex_init(&c->s[i].mutex, NULL) != 0)
			return (0);
	}
	return (1);
}

int					start_philosophers(t_core *c)
{
	int				i;

	i = -1;
	while (++i < PN)
	{
		if (pthread_create(&c->p[i].thread, NULL,
							start_philosopher, &c->p[i]) != 0)
			return (0);
	}
	return (1);
}

int					init_philosophers(t_core *c)
{
	int				i;

	i = -1;
	while (++i < PN)
	{
		c->p[i].life = MAX_LIFE;
		c->p[i].c = c;
		c->p[i].state = RESTING;
		c->p[i].left_locked = 0;
		c->p[i].right_locked = 0;
		c->p[i].i = i;
		c->p[i].stop = 0;
	}
	return (1);
}
