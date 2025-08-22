#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Bureaucrat captain(1, "ycho2");
		Intern	   intern;
		AForm*	   form;

		form = intern.makeForm("presidential pardon", "home");
		captain.signForm(*form);
		captain.executeForm(*form);
		delete form;
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
	catch (Intern::FormNameInvalidException e)
	{
		std::cout << "** Intern error: Form name INVALID!!! **" << std::endl;
	}

	return (0);
}
