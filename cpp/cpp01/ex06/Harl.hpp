/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:54:26 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/10 09:23:35 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum param_type {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	ELSE,
};

class	Harl
{
	private:
		void			debug();
		void			info();
		void			warning();
		void			error();

		typedef struct s_member_func
		{
			std::string	level;
			void 		(Harl::*func)(void);
			int			is_on;	
		}				t_member_func;

		t_member_func	list[4];
		int				checkLevel(t_member_func &one, std::string level);
		int				runWithoutIf(void (Harl::*func)(void), int ret, int is_on);
		int				param_check(std::string param);

	public:
		Harl(std::string param);
		~Harl();
		void	complain(std::string level);
};
