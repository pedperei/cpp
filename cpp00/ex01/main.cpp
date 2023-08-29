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