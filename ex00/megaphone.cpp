/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:25 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/02 15:23:31 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string str;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			str = av[i];
			for (unsigned long j = 0; j < str.length(); j++)
				str[j] = std::toupper(str[j]);
			std::cout << str << " ";	
		}
	}
	std::cout << std::endl;
	return (0);
}
