/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 21:37:44 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/28 21:37:45 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void					init_graphics(t_graphics *g)
{
	g->p_padding = 30.0f;
	g->s_padding = 5.0f;
	g->s_size = 35.0f;
	g->p_radius = 30.0f;
	g->t_x = 50.0f;
	g->t_y = 150.0f;
	g->t_width = PN * ((g->p_radius * 2) + g->p_padding) - g->p_padding;
	g->t_height = 50.0f;
}
