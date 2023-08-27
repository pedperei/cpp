/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:32:52 by pedperei          #+#    #+#             */
/*   Updated: 2023/08/25 18:53:27 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

int main (void)
{
    PhoneBook PhoneBook;
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
            PhoneBook.add();
        }
        else if (input.compare("SEARCH") == 0)
            PhoneBook.add();
    }
}