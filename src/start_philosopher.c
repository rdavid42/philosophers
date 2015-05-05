/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:52:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:52:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

static void			end_philosopher(t_philosopher *p, t_stick *s[2])
{
	(void)s;
	if (p->life <= 0)
	{
		p->life = 0;
		p->state = DEAD;
	}
	p->stop = -1;
}

void				*start_philosopher(void *pa)
{
	t_philosopher	*p;
	t_stick			*s[2];
	t_philosopher	*n[2];

	p = (t_philosopher *)pa;
	s[0] = &p->c->s[p->i];
	s[1] = &p->c->s[(p->i + 1) % PN];
	n[0] = &p->c->p[(p->i - 1) < 0 ? PN - 1 : (p->i - 1)];
	n[1] = &p->c->p[(p->i + 1) % PN];
	while (!p->stop)
	{
		if (p->life > 0)
		{
			if (p->state == RESTING)
				philosopher_rest(p, s, n);
			else if (p->state == EATING)
				philosopher_eat(p, s, n);
			else if (p->state == THINKING)
				philosopher_think(p, s, n);
		}
		else
			usleep(MW);
	}
	end_philosopher(p, s);
	return (NULL);
}
