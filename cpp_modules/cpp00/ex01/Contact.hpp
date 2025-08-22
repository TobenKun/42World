/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:13:57 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/02 09:24:37 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_secret;
	public:
		Contact();
		~Contact();
		void	set_fname(std::string name);
		void	set_lname(std::string name);
		void	set_nname(std::string name);
		void	set_pnum(std::string num);
		void	set_sec(std::string	s);
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nname(void) const;
		std::string	get_pnum(void) const;
		std::string	get_sec(void) const;
};
