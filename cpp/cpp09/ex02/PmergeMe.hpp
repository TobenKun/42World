/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:58:00 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/28 12:25:52 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <list>
#include <vector>

class PmergeMe
{
  public:
	static std::vector<int> mergeInsertSort(std::vector<int> &, int);
	static std::list<int>	mergeInsertSort(std::list<int> &);

	static std::vector<int> &ford(std::vector<int> &, int);

  private:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();
};
