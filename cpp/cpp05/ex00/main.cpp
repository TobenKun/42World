#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int main(void)
{
	int test = 0;
start:
	try
	{
		if (test == 0)
		{
			std::cout << "\n***** Too High exception check *****" << std::endl;
			Bureaucrat unit(3, "ycho2");
			for (;;)
			{
				std::cout << unit << std::endl;
				unit.upGrade();
			}
		}

		if (test == 1)
		{
			std::cout << "\n***** Too Low exception check *****" << std::endl;
			Bureaucrat unit(147, "ycho3");
			for (;;)
			{
				std::cout << unit << std::endl;
				unit.downGrade();
			}
		}

		if (test == 2)
		{
			std::cout << "\n***** 생성시 예외처리 체크 *****" << std::endl;
			Bureaucrat unit3(151, "ycho4");
		}
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Bureaucrat Grade Too High exception " << std::endl;
		test++;
		goto start;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Bureaucrat Grade Too Low exception " << std::endl;
		test++;
		goto start;
	}
	catch (const std::exception& e)
	{
		std::cerr << "something went wrong" << std::endl;
		test++;
		goto start;
	}
}
