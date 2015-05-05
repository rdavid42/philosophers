/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_rest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:52:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:52:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

void				philosopher_rest(t_philosopher *p, t_stick *s[2],
										t_philosopher *n[2])
{
	size_t			elapsed;

	unlock_sticks(p, s);
	p->request = REQUEST_NONE;
	if (!p->sleep)
	{
		usleep(MS(REST_T));
		p->sleep = 1;
		philosopher_try_action(p, s, n);
	}
	else
	{
		elapsed = 0;
		while (elapsed < MS(REST_T))
		{
			usleep(MW);
			philosopher_try_action(p, s, n);
			if (p->state != RESTING)
			{
				p->sleep = 0;
				break ;
			}
			elapsed += MW;
		}
	}
}
