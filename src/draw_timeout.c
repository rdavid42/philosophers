/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_timeout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 17:53:25 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/04 17:53:25 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				draw_timeout(t_core *c)
{
	char			*tmp;

	glColor3f(0.0f, 0.0f, 0.0f);
	draw_text(c->g.p_padding, 300, "timeout: ", F1);
	tmp = itoa(c->current_time);
	draw_text(c->g.p_padding + 65, 300, tmp, F1);
	free(tmp);
}
