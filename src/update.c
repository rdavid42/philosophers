/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:13:05 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:13:05 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

int					philosophers_remove_life(t_core *c)
{
	int						i;

	i = -1;
	while (++i < PN)
	{
		if (c->p[i].state != EATING)
		{
			c->p[i].life -= 1;
			if (c->p[i].life < 0)
				c->p[i].life = 0;
		}
	}
	return (1);
}

int					clockwork(t_core *c)
{
	static int				start_time = 0;
	static int				current_time = 0;
	int						tmp_time;

	if (!start_time)
		start_time = time(NULL);
	tmp_time = current_time;
	current_time = time(NULL) - start_time;
	if (tmp_time != current_time)
		philosophers_remove_life(c);
	if (current_time == TIMEOUT)
		c->stop_sim = 1;
	return (1);
}

void				print_dead_philosopher(t_philosopher *p)
{
	int						e;
	char					*phi;

	phi = itoa(p->i + 1);
	e = write(1, "Philosopher ", 14);
	e = write(1, phi, slen(phi));
	e = write(1, " died !\n", 8);
	(void)e;
}

void				update(t_core *c)
{
	int						i;

	if (c->dead_count == 0)
	{
		i = -1;
		while (++i < PN)
		{
			if (c->p[i].life == 0)
			{
				c->dead_count++;
				print_dead_philosopher(&c->p[i]);
			}
		}
		clockwork(c);
	}
	else
		c->stop_sim = 1;
}
