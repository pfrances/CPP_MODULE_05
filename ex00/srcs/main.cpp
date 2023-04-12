/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 23:02:41 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	update_grade(Bureaucrat& b, void (Bureaucrat::*func)(void)) {
	try {
		(b.*func)();
	} catch (const std::exception& e) {
		std::cerr << "exception catched: " << e.what() << std::endl;
	}
	std::cout << b << std::endl;
}

Bureaucrat*	instanceBureaucrat(const std::string Name, const int Grade) {
	try {
		Bureaucrat *b = new Bureaucrat(Name, Grade);
		return b;
	} catch (const std::exception& e) {
		std::cerr << "exception catched: " << e.what() << std::endl;
	}
	return NULL;
}

int	main(void) {
	Bureaucrat *b1 = instanceBureaucrat("b1", 1);
	std::cout << *b1 << std::endl;
	update_grade(*b1, &Bureaucrat::decrementGrade);
	update_grade(*b1, &Bureaucrat::incrementGrade);
	update_grade(*b1, &Bureaucrat::incrementGrade);

	std::cout << std::endl;

	Bureaucrat *b2 = instanceBureaucrat("b2", 150);
	std::cout << *b2 << std::endl;
	update_grade(*b2, &Bureaucrat::decrementGrade);

	std::cout << std::endl;

	Bureaucrat *b3 = instanceBureaucrat("b3", 0);
	std::cout << "b3 ptr is equal to " << b3 << std::endl;

	Bureaucrat *b4 = instanceBureaucrat("b4", 151);
	std::cout << "b4 ptr is equal to " << b4 << std::endl;

	std::cout << std::endl;

	delete b1;
	delete b2;

	return 0;
}
