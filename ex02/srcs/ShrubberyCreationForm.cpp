/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:54:36 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/14 12:01:12 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

#define FORM_NAME "ShrubberyCreationForm"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm(FORM_NAME, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_("default") {
	std::cout << "[ShrubberyCreationForm] default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string Target ) : AForm(FORM_NAME, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_(Target) {
	std::cout << "[ShrubberyCreationForm] typed constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), Target_(other.getTarget()) {
	std::cout << "[ShrubberyCreationForm] copy constructor called." << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->Target_ = other.getTarget();
	}
	std::cout << "[ShrubberyCreationForm] asignment called." << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "[ShrubberyCreationForm] destructor called." << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget( void ) const {
	return this->Target_;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {

	if (this->checkRequirement(executor)) {
		std::string	filename = this->Target_ + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (!file.is_open()) {
			std::cerr << "Unable to open '" << filename << "'." << std::endl;
			return ;
		}
		for (int i = 0; i < 10; i++) {
			file << "     *\n    ***\n   *****\n  *******\n *********\n***********\n    |||\n" << std::endl;
		}
		file.close();
	}
}
