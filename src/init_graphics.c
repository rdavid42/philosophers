
#include "core.h"

void					init_graphics(t_core *c, t_graphics *g)
{
	g->t_radius = 120.0f;
	g->p_dist = 30.0f;
	g->p_radius = 20.0f;
	g->h_radius = 5.0f;
	g->s_size = 10.0f;
	g->circle_p = 30;
	g->cx = c->width / 2;
	g->cy = c->height / 2;
}