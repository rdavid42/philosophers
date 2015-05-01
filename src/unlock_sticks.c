/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_sticks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 21:37:44 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/28 21:37:45 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				unlock_sticks(t_philosopher *p, t_stick *s[2])
{
	if (s[0]->owner == p->i)
	{
		pthread_mutex_unlock(&s[0]->mutex);
		s[0]->owner = -1;
	}
	if (s[1]->owner == p->i)
	{
		pthread_mutex_unlock(&s[1]->mutex);
		s[1]->owner = -1;
	}
}
