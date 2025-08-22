/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:50:25 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/09 16:37:09 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
template <typename T, typename FUN>
void iter(T* arr, size_t len, FUN f)
{
	for (size_t i = 0; i < len; i++) f(arr[i]);
}
