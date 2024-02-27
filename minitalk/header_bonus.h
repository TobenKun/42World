/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:40:12 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/04 17:26:44 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include "new_libft/libft.h"
# include <unistd.h>
# include <signal.h>

// server_main.c
void	exec_server(void);
void	sigusr1_handler(void);
void	sigusr2_handler(void);
// client_main.c
void	bit_shooter(int server_pid, char c);
void	send_null(int server_pid);
void	send_pid(int server_pid);
void	su1_handler(void);

#endif
