/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:11:09 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/03 16:02:27 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();	
		int		add(void);
		void	search(void);

	private:
		Contact		book[8];
		int			index;
		std::string	cuttercal(const std::string& s) const;
		void		print_info(int index) const;
		int			space_checker(const std::string& s) const;
};
