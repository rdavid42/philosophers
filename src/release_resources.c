/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_resources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:24 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int					release_resources(t_core *c)
{
	int				i;

	i = -1;
	while (++i < PN)
	{
		if (pthread_mutex_destroy(&c->s[i].mutex) != 0)
			return (0);
	}
	return (1);
}
