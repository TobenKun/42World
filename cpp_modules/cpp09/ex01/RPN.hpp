/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:17:47 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/18 19:55:09 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class RPN
{
  public:
	static double doRPN(const std::string&);

  private:
	RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);
	~RPN();
};
