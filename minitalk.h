/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:11:27 by mrollo            #+#    #+#             */
/*   Updated: 2022/03/11 16:18:26 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <libc.h>
# include <unistd.h>

typedef struct minitalk
{
	int		bit;
	char	c;
}			t_minitalk;

#endif
