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

#include <stddef.h>
#include <stdlib.h>
#include "core.h"

void				*start_philosopher(void *a)
{
	t_pargs			*pa = (t_pargs *)a;

	(void)pa;
	free(pa);
	return (NULL);
}

int					init_philosophers(t_core *c)
{
	int				i;
	// int				err;
	t_pargs			*pa;

	i = 0;
	while (i < PN)
	{
		if (!(pa = malloc(sizeof(t_pargs))))
			return (0);
		pa->core = c;
		pa->i = i;
		// if (!(err = pthread_create(&c->p[i].thread, NULL,
									// start_philosopher, pa)))
			// return (0);
		free(pa);
		++i;
	}
	return (1);
}
