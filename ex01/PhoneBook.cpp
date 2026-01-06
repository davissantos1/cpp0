/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:42:01 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/06 19:34:20 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	grab_input()
{
	std::string input;

	while (1)
	{
		if(!std::getline(std::cin, input))
			break ;
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

	std::cout << "_____________________________________________";
	std::cout << std::endl;
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

static void	show_contact(Contact contact, int index)
{
	std::cout << "------- Contact Information -------" << index << std::endl;
	std::cout << "Index number: #" << index << std::endl;
	std::cout << "First Name: " + contact.getFirstName() << std::endl;
	std::cout << "Last Name: " + contact.getLastName() << std::endl;
	std::cout << "Nickname: " + contact.getNickname() << std::endl;
	std::cout << "Phone Number: " + contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " + contact.getDarkestSecret() << std::endl;
	std::cout << "--------------------------- -------" << index << std::endl;
}

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_size = 0;
}

void	PhoneBook::add()
{
	std::cout << "Type in the contact details: " << std::endl;
	std::cout << std::endl;
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
	int option;
	int	i;

	i = -1;
	if (this->_size == 0)
	{
		std::cout << "There are no contacts inside the PhoneBook!";
		std::cout << std::endl;
		std::cout << std::endl;
		return ;
	}
	while (++i < this->_size)
		print_row(this->_contacts[i], i);
	std::cout << "_____________________________________________";
	std::cout << std::endl;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "Search options: " << std::endl;
		std::cout << "Input the contact's index (0 through 7)" << std::endl;
		std::cout << "Input -1 to leave the search" << std::endl;
		std::cout << std::endl;
		std::cin >> option;
		if (std::cin.eof())
			break ;
		if (option >= 0 && option <= 7)
			show_contact(this->_contacts[option], option);
		else if (option == -1)
			break ;
		else
			std::cout << "Wrong option, try again!" << std::endl;
	}
}
