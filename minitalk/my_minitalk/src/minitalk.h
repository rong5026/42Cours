/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:15:56 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/05/30 22:15:56 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define NINITALK_H

# include <unistd.h>
# include <signal.h>


typedef struct content
{
	pid_t   pid;
	char    *msg;
}   CONTENT;

#endif
