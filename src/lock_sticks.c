/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_sticks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 21:37:44 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/28 21:37:45 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				lock_sticks(t_philosopher *p, t_stick *s[2])
{
	if (!pthread_mutex_lock(&s[0]->mutex))
		s[0]->owner = p->i;
	if (!pthread_mutex_lock(&s[1]->mutex))
		s[1]->owner = p->i;
}
