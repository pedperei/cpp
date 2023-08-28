/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:32:52 by pedperei          #+#    #+#             */
/*   Updated: 2023/08/28 15:00:26 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

int main (void)
{
    PhoneBook phonebook;
    std::string input = "";

    std::cout << "Type ADD to add contact" << std::endl;
    std::cout << "Type SEARCH to search contact" << std::endl;
    std::cout << "Type EXIT to exit program" << std::endl;
    

    while (input.compare("EXIT"))
    {
        std::cout << "->";
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
        {
            phonebook.add();
        }
        else if (input.compare("SEARCH") == 0)
            phonebook.search(phonebook);
        if (std::cin.eof())
            return (1);
    }
}