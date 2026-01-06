/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:42:01 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/06 14:45:19 by dasimoes         ###   ########.fr       */
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

static void	print_row(Contact contact, int index)
{
	std::string firstName = contact.getFirstName();
	std::string lastName = contact.getLastName();
	std::string nickname = contact.getNickname();

	firstName = (firstName.size() > 10) ? firstName.substr(0,9) + "." : firstName;
	lastName = (lastName.size() > 10) ? lastName.substr(0,9) + "." : lastName;
	nickname = (nickname.size() > 10) ? nickname.substr(0,9) + "." : nickname;

	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << index << "|";
	std::cout << std::setw(10);
	std::cout << firstName << "|";
	std::cout << std::setw(10);
	std::cout << lastName << "|";
	std::cout << std::setw(10);
	std::cout << nickname << "|";
	std::cout << std::endl;
}

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_size = 0;
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
	if (this->_size >= 0 && this->_size <= 7)
		this->_size++;
}

void	PhoneBook::search()
{
	int	i;

	i = -1;
	if (this->_size == 0)
	{
		std::cout << "There are no contacts inside the PhoneBook!";
		std::cout << std::endl;
		return ;
	}
	std::cout << std::setfill('-') << std::setw(40);
	while (++i < this->_size)
		print_row(this->_contacts[i], i);
	std::cout << std::setfill('-') << std::setw(40);
}
