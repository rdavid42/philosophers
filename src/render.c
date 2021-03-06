/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:24 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

void				render(t_core *c)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gl_enable_2d(0, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	draw_philosophers(c);
	draw_table(c);
	draw_sticks(c);
	if (c->stop_sim && c->dead_count == 0)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		draw_text(c->width / 2 - 100, c->height - 100, SUCCESS_STR, F1);
	}
	else if (c->dead_count > 0)
		draw_dead_str(c);
	draw_timeout(c);
	gl_disable_2d();
	glFlush();
}
