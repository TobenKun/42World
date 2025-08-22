/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:48:54 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/21 22:56:51 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	uintptr_t ptr;
	Data*	  my_data = new Data;
	Data*	  de_ptr;

	my_data->s = (char*)&"hello world!";
	ptr = Serializer::serialize(my_data);
	std::cout << ptr << ", " << (reinterpret_cast<Data*>(ptr))->s << std::endl;

	de_ptr = Serializer::deserialize(ptr);
	std::cout << reinterpret_cast<uintptr_t>((de_ptr)) << ", " << de_ptr->s
			  << std::endl;
}
