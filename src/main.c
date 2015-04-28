/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:15 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:16 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			main(int argc, char **argv)
{
	t_core		core;

	if (!init_core(&core))
		return (1);
#ifdef linux
	glutInit(&argc, argv);
#endif
	init_graphics(&core, &core.g);
	if (!init_sticks(&core))
		return (1);
	if (!init_philosophers(&core))
		return (1);
	if (!start_philosophers(&core))
		return (1);
	loop(&core);
	(void)argc;
	(void)argv;
	return (0);
}
