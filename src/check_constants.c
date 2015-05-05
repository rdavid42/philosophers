/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 18:55:17 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/04 18:55:17 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "constants.h"

int					check_constants(void)
{
	if (MAX_LIFE < 1)
		return (!write(2, "MAX_LIFE must be superior or equal to 1 !\n", 42));
	if (EAT_T < 1)
		return (!write(2, "EAT_T must be superior or equal to 1 !\n", 39));
	if (REST_T < 1)
		return (!write(2, "REST_T must be superior or equal to 1 !\n", 40));
	if (THINK_T < 1)
		return (!write(2, "THINK_T must be superior or equal to 1 !\n", 41));
	if (TIMEOUT < 1)
		return (!write(2, "TIMEOUT must be superior or equal to 1 !\n", 41));
	return (1);
}
