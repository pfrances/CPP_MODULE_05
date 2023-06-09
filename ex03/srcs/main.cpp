/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/14 11:58:13 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

void	update_grade(Bureaucrat& b, void (Bureaucrat::*func)(void)) {
	try {
		(b.*func)();
	} catch (const std::exception& e) {
		std::cerr << "exception catched: " << e.what() << std::endl;
	}
	std::cout << b << std::endl;
}

int	main(void) {
	srand(time(NULL));

	Bureaucrat b1("b1", 1);

	std::cout << b1 << std::endl;

	update_grade(b1, &Bureaucrat::decrementGrade);
	update_grade(b1, &Bureaucrat::incrementGrade);
	update_grade(b1, &Bureaucrat::incrementGrade);

	Bureaucrat b2("b2", 150);

	std::cout << b2 << std::endl;

	update_grade(b2, &Bureaucrat::decrementGrade);

	std::cout << std::endl;

	ShrubberyCreationForm f1("Garden");

	b2.signForm(f1);
	b1.signForm(f1);
	b1.signForm(f1);

	std::cout << std::endl;

	b2.executeForm(f1);
	b1.executeForm(f1);

	RobotomyRequestForm f2("Kevin");

	b2.signForm(f2);
	b1.signForm(f2);
	b1.signForm(f2);

	std::cout << std::endl;

	b2.executeForm(f2);
	b1.executeForm(f2);

	std::cout << std::endl;

	PresidentialPardonForm f3("John");

	b2.signForm(f3);
	b1.signForm(f3);
	b1.signForm(f3);

	std::cout << std::endl;

	b2.executeForm(f3);
	b1.executeForm(f3);

	Intern someRandomIntern;
	AForm* f4 = someRandomIntern.makeForm("robotomy request", "Bender");
	b2.executeForm(*f4);
	delete f4;

	std::cout << std::endl;

	AForm* f5 = someRandomIntern.makeForm("presidential pardon", "Tom");
	b2.executeForm(*f5);
	b1.signForm(*f5);
	b2.executeForm(*f5);
	delete f5;

	std::cout << std::endl;

	AForm* f6 = someRandomIntern.makeForm("Unvalid Name form", "Bob");
	std::cout << "f6 ptr is equal to " << f6 << std::endl;

	std::cout << std::endl;

	return 0;
}
