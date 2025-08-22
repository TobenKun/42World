#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat unit(2, "ycho2");
		Form	   mission("mision1", 1, 1);

		std::cout << " *** 기본 테스트 *** " << std::endl;
		std::cout << unit << std::endl;
		std::cout << mission << std::endl;
		unit.signForm(mission);
		std::cout << "\nunit upgrade" << std::endl;
		unit.upGrade();
		std::cout << unit << std::endl;
		unit.signForm(mission);
		std::cout << std::endl;

		std::cout << " *** 폼 생성 테스트 *** " << std::endl;
		Form wrong_form("wrong", 0, 1);
		Form wrong_form2("wrong", 1, 153);
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << "** Form error: Grade is TOO HIGH!!!! **" << std::endl;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << "** Form error:Grade is TOO LOW!!!! **" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << "** Bureaucrat error:Grade is TOO HIGH!!!! **"
				  << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << "** Bureaucrat error:Grade is TOO LOW!!!! **" << std::endl;
	}

	return (0);
}
