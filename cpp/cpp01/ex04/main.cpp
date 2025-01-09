/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:56:48 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/09 17:09:32 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);

	std::string		file_name = av[1];
	std::fstream	original_file(file_name, std::ios_base::in);
	if (!original_file.is_open())
		return (1);

	std::fstream	replaced_file(file_name + ".replace", std::ios_base::out);
	std::string		one_line;
	std::string		to_erase = av[2];
	std::string		to_put = av[3];

	while (std::getline(original_file, one_line))
	{
		unsigned long index = one_line.find(to_erase);
		while (index != std::string::npos)
		{
			one_line.erase(index, to_erase.length());
			one_line.insert(index, to_put);
			index = one_line.find(to_erase);
		}
		replaced_file << one_line << std::endl;
	}	
	original_file.close();
	replaced_file.close();
	return (0);
}
