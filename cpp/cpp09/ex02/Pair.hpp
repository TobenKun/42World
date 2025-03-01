/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:26:24 by sangshin          #+#    #+#             */
/*   Updated: 2025/02/17 05:20:40 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Pair
{
  public:
	Pair(int value, void* pair);
	Pair(const Pair&);
	Pair& operator=(const Pair&);
	~Pair();

	int		   value;
	Pair*	   pair;
	static int compare_count;

	static bool comp(const Pair&, const Pair&);

  private:
};
