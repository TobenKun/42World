#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat			   unit(2, "ycho2");
		ShrubberyCreationForm  test("home");
		RobotomyRequestForm	   test2("father");
		PresidentialPardonForm test3("mother");

		std::cout << test << std::endl;
		unit.signForm(test);
		unit.executeForm(test);

		std::cout << std::endl;

		std::cout << test2 << std::endl;
		unit.signForm(test2);
		unit.executeForm(test2);

		std::cout << std::endl;

		std::cout << test3 << std::endl;
		unit.signForm(test3);
		unit.executeForm(test3);
	}
	catch (AForm::GradeTooHighException e)
	{
		std::cout << "** Form error: Grade is TOO HIGH!!!! **" << std::endl;
	}
	catch (AForm::GradeTooLowException e)
	{
		std::cout << "** Form error:Grade is TOO LOW!!!! **" << std::endl;
	}
	catch (AForm::UnsignedExecuteException e)
	{
		std::cout << "** Form error:Form is NOT SIGNED!!!! **" << std::endl;
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
