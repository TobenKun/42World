/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:20:26 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/25 16:44:56 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void check() { system("leaks materia"); }

int main()
{
	atexit(check);

	if (1)
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria*	tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		std::cout << "\n-----------------------------" << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);
		std::cout << "\n-----------------------------" << std::endl;
		delete bob;
		delete me;
		delete src;
		return 0;
	}
	else
	{
		std::cout << "***** 딥카피 테스트 *****" << std::endl;
		Character* original = new Character("1");
		original->equip(new Ice());
		original->equip(new Cure());
		Character copied(*original);
		delete original;
		copied.use(0, copied);
		copied.use(1, copied);
		std::cout << std::endl;

		std::cout << "\n***** 인벤토리 초과 장착 테스트 *****" << std::endl;
		copied.equip(new Ice());
		copied.equip(new Ice());
		copied.equip(new Ice());
		copied.equip(new Ice());
		copied.equip(new Ice());
		copied.equip(new Ice());

		std::cout << "\n***** 인벤토리 초과 해제 테스트 *****" << std::endl;
		// 정상 해제
		copied.unequip(0);
		copied.unequip(1);
		copied.unequip(2);
		copied.unequip(3);
		// 해제된 인덱스 다시 해제
		copied.unequip(0);
		//  잘못된 인덱스 전달
		copied.unequip(4);
		copied.unequip(-1);

		std::cout << "\n***** 해제된 마테리아 사용 *****" << std::endl;
		copied.use(0, copied);
		copied.use(1, copied);
		copied.use(2, copied);
		copied.use(3, copied);

		std::cout << "\n***** 해제 후 재장착 *****" << std::endl;
		copied.equip(new Ice());
		copied.equip(new Cure());
		copied.use(0, copied);
		copied.use(1, copied);
	}
}
