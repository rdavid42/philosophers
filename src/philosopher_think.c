/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_think.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:52:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:52:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

void				philosopher_think(t_philosopher *p, t_stick *s[2],
										t_philosopher *n[2])
{
	size_t			elapsed;

	elapsed = 0;
	while (elapsed < MS(THINK_T))
	{
		usleep(MW);
		if (p->stop)
			return ;
		if (p->request == REQUEST_STICK)
		{
			p->state = RESTING;
			p->request = REQUEST_NONE;
			unlock_sticks(p, s);
			return ;
		}
		philosopher_try_action(p, s, n);
		if (p->state != THINKING)
			return ;
		elapsed += MW;
	}
	philosopher_try_action(p, s, n);
}
