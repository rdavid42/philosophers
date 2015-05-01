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
	unlock_sticks(p, s);
	p->request = REQUEST_NONE;
	usleep(MS(REST_T));
	philosopher_try_action(p, s, n);
}
