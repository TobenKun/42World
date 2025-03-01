/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:18:58 by sangshin          #+#    #+#             */
/*   Updated: 2025/02/17 12:33:14 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "Pair.hpp"

class PmergeMe
{
	typedef std::vector<Pair> Pvec;
	typedef std::deque<Pair>  Pdq;
	typedef std::list<Pair>	  Plist;

  public:
	PmergeMe();
	~PmergeMe();

	void setDebugMode(bool);

	std::vector<int> FJSort(std::vector<int>&);
	std::deque<int>	 FJSort(std::deque<int>&);
	std::list<int>	 FJSort(std::list<int>&);

  private:
	PmergeMe(PmergeMe&);
	PmergeMe& operator=(PmergeMe&);

	Pvec  InfiniteTsukuyomi(Pvec);
	Pdq	  InfiniteTsukuyomi(Pdq);
	Plist InfiniteTsukuyomi(Plist);

	void winnerComesFirst(Pvec& vec);
	void attachLosers(Pvec& vec, Pvec& winner);
	void createChains(Pvec& sorted_vec, Pvec& main_chain, Pvec& sub_chain);
	void insertSubChain(Pvec& main_chain, Pvec& sub_chain);
	void insertRemaining(Pvec& vec, Pvec& main_chain);

	void winnerComesFirst(Pdq& dq);
	void attachLosers(Pdq& dq, Pdq& winner);
	void createChains(Pdq& sorted_dq, Pdq& main_chain, Pdq& sub_chain);
	void insertSubChain(Pdq& main_chain, Pdq& sub_chain);
	void insertRemaining(Pdq& dq, Pdq& main_chain);

	void winnerComesFirst(Plist& list);
	void attachLosers(Plist& list, Plist& winner);
	void createChains(Plist& sorted_list, Plist& main_chain, Plist& sub_chain);
	void insertSubChain(Plist& main_chain, Plist& sub_chain);
	void insertRemaining(Plist& list, Plist& main_chain);

	int	 getTk(int);
	void getInsert_seq(int size, int* arr);

	template <typename T>
	void ft_swap(T& first, T& second)
	{
		T tmp = first;
		first = second;
		second = tmp;
	}

	template <typename C>
	void printDebug(C& p, const std::string& name)
	{
		if (debug_flag == false) return;

		std::cout << "\n--------------" + name << "--------- " << std::endl;
		int i = 0;
		for (typename C::iterator it = p.begin(); it != p.end(); it++, i++)
		{
			std::cout << "vec[" << i << "]: " << it->value;
			Pair* ptr = it->pair;
			while (ptr != 0)
			{
				std::cout << " -> " << ptr->value;
				ptr = ptr->pair;
			}
			std::cout << std::endl;
		}
		std::cout << "--------------print end-----------\n" << std::endl;
	}

	int	 depth;
	bool debug_flag;  // if set, FJSort function will print sorting sequence
};
