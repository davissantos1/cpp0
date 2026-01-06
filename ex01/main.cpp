/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:57:40 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/06 14:43:46 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static	void	init_msg()
{
	std::cout << "Type one of the options below: " << std::endl << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: ends the program" << std::endl << std::endl;
}

int	main(int ac, char **av)
{
	PhoneBook phonebook;
	std::string input;

	(void)av;
	if (ac != 1)
	{
		std::cout << "Phonebook error: no parameters supported" << std::endl;
		return (1);
	}
	else
	{
		while (1)
		{
			init_msg();
			std::getline(std::cin, input);
			if (input == "ADD")
				phonebook.add();
			else if (input == "SEARCH")
				phonebook.search();
			else if (input == "EXIT")
				break ;
			else
				std::cout << std::endl;
		}
	}
	return (0);
}
