/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:42:01 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/04 21:21:29 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	grab_input()
{
	std::string input;

	while (1)
	{
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Nothing typed, try again";
		else
			break ;
		std::cout << std::endl;
	}
	return (input);
}

PhoneBook::PhoneBook()
{
	this->_index = 0;
}

void	PhoneBook::add()
{
	std::cout << "Type in the contact details: " << std::endl;
	std::cout << "First Name: ";
	std::cout << std::endl;
	this->_contacts[this->_index].setFirstName(grab_input());
	std::cout << std::endl;
	std::cout << "Last Name: ";
	this->_contacts[this->_index].setLastName(grab_input());
	std::cout << std::endl;
	std::cout << "Nickname: ";
	this->_contacts[this->_index].setNickname(grab_input());
	std::cout << std::endl;
	std::cout << "Phone Number: ";
	this->_contacts[this->_index].setPhoneNumber(grab_input());
	std::cout << std::endl;
	std::cout << "Darkest Secret: ";
	this->_contacts[this->_index].setDarkestSecret(grab_input());
	std::cout << std::endl;
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
}

void	PhoneBook::search()
{
	std::cout << "I will search shit" << std::endl;
}
