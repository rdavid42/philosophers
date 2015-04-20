/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:08 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:09 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int					init_core(t_core *core)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (sdl_error(0));
	core->width = 1920;
	core->height = 1080;
	if (!(core->window = SDL_CreateWindow("Philosophers",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									core->width,
									core->height,
									SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)))
		return (sdl_error(0));
	if (!(core->context = SDL_GL_CreateContext(core->window)))
		return (sdl_error(0));
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)core->width / (double)core->height, 0.05, 10);
	glEnable(GL_BLEND);
	glMatrixMode(GL_PROJECTION);
	return (1);
}
