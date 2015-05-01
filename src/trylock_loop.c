/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trylock_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:52:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:52:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

int					trylock_loop(t_philosopher *p, t_stick *s)
{
	int				l;
	int				timeout;

	l = 1;
	timeout = 0;
	while (l != 0)
	{
		if (p->stop == 1 || timeout >= MS(1))
			return (0);
		usleep(MW);
		timeout += MW;
		l = pthread_mutex_trylock(&s->mutex);
	}
	s->owner = p->i;
	return (1);
}
