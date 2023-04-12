/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 22:24:32 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	virtual	~RobotomyRequestForm( void );

	const std::string&	getTarget( void ) const;

	void				execute(const Bureaucrat& executor) const;

private:
	std::string			Target_;
	const static int	GRADE_TO_SIGN_ = 72;
	const static int	GRADE_TO_EXECUTE_ = 45;
};

#endif
