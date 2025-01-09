/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:54:26 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/10 08:46:34 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>


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
		}				t_member_func;

		t_member_func	list[4];
		int				checkLevel(t_member_func &one, std::string level);
		int				runWithoutIf(void (Harl::*func)(void), int ret);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
