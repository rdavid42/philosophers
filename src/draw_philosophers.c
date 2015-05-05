/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:24 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				draw_philosophers(t_core *c)
{
	int						i;
	float					x;
	float					y;
	char					*tmp;
	static char const		*state[4] =

	{ "Resting", "Eating", "Thinking", "Dead" };
	x = c->g.t_x + c->g.p_radius;
	y = c->g.t_y + c->g.p_radius + 2 * c->g.p_padding;
	i = -1;
	while (++i < PN)
	{
		tmp = itoa(c->p[i].life);
		draw_text(x - c->g.p_radius, y + c->g.p_radius + c->g.p_padding,
					state[c->p[i].state], F1);
		draw_text(x - c->g.p_radius, y + c->g.p_radius + c->g.p_padding + 20,
					"life: ", F1);
		draw_text(x - c->g.p_radius + 40,
					y + c->g.p_radius + c->g.p_padding + 20, tmp, F1);
		draw_circle(x, y, c->g.p_radius, 20);
		x += c->g.p_radius * 2 + c->g.p_padding;
		free(tmp);
	}
}
