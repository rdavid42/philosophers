/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_try_action.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:52:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:52:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void		neighbours_thinking_action(t_philosopher *p, t_stick *s[2],
											t_philosopher *n[2])
{
	n[0]->request = REQUEST_STICK;
	n[1]->request = REQUEST_STICK;
	if (!pthread_mutex_trylock(&s[0]->mutex))
		s[0]->owner = p->i;
	if (!pthread_mutex_trylock(&s[1]->mutex))
		s[1]->owner = p->i;
	if (s[0]->owner == p->i && s[1]->owner == p->i)
		p->state = EATING;
}

static void		right_owned_action(t_philosopher *p, t_stick *s[2],
									t_philosopher *n[2])
{
	if (n[0]->state == THINKING)
	{
		n[0]->request = REQUEST_STICK;
		if (!pthread_mutex_trylock(&s[0]->mutex))
		{
			s[0]->owner = p->i;
			p->state = EATING;
		}
	}
	else if (n[0]->state == EATING)
		p->state = THINKING;
}

static void		left_owned_action(t_philosopher *p, t_stick *s[2],
									t_philosopher *n[2])
{
	if (n[1]->state == THINKING)
	{
		n[1]->request = REQUEST_STICK;
		if (!pthread_mutex_trylock(&s[1]->mutex))
		{
			s[1]->owner = p->i;
			p->state = EATING;
		}
	}
	else if (n[1]->state == EATING)
		p->state = THINKING;
}

void			philosopher_try_action(t_philosopher *p, t_stick *s[2],
										t_philosopher *n[2])
{
	try_lock_sticks(p, s);
	if (s[0]->owner == p->i && s[1]->owner == p->i)
		p->state = EATING;
	else
	{
		if ((s[0]->owner == p->i) ^ (s[1]->owner == p->i))
			p->state = THINKING;
		if (n[0]->state == THINKING && n[1]->state == THINKING)
			neighbours_thinking_action(p, s, n);
		else if (s[1]->owner == p->i)
			right_owned_action(p, s, n);
		else if (s[0]->owner == p->i)
			left_owned_action(p, s, n);
		else
			p->state = RESTING;
	}
}
