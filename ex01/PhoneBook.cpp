#include "PhoneBook.hpp"

PhoneBook::PhoneBook()  {_nb_contact = 0;}

PhoneBook::~PhoneBook(){}

void PhoneBook::search()
{
    if (!_nb_contact)
        return ;
    std::string index;
    std::cout << "Index" << " | "<< " Firstname" << " | " << "  Lastname" << " | " << "  Nickname" << std::endl;
    for(uint8_t i = 0; i < _nb_contact; i++)
        std::cout << "    " << i + 1 << " | " << _contact[i].getFormattedValue(Contact::FIRSTNAME) << " | " << _contact[i].getFormattedValue(Contact::LASTNAME) << " | " << _contact[i].getFormattedValue(Contact::NICKNAME) << std::endl;
    std::cout << "Please enter the index (or 'q' to quit):" << std::endl;
    for(;;)
    {
        std::cin >> index;
        if (index == "q")
        {
            std::cout << "Exiting the search." << std::endl;
            break;
        }
        int x = atoi(index.c_str());
        if (x == 0 || x > _nb_contact)
        {
            std::cout << "Invalid input. Please enter a valid index or 'q' to quit." << std::endl;
            continue;
        }
        std::cout << "Index" << std::setw(15) << "Firstname" << std::setw(15) << "Lastname" << std::setw(15) << "Nickname" << std::setw(20) << "Phone Number" << std::setw(20) << "Darkest Secret" << std::endl;
        std::cout << std::setw(5) << x << std::setw(15) << _contact[x - 1].getFirstname() << std::setw(15) << _contact[x - 1].getLastname() << std::setw(15) << _contact[x - 1].getNickname() << std::setw(20) << _contact[x - 1].getPhoneNumber() << std::setw(20) << _contact[x - 1].getDarkestSecret() << std::endl;
        std::cout << "Want to search another contact, or quit? (Enter index or 'q' to quit):" << std::endl;
    }
}

void PhoneBook::addContactintoPhoneBook(uint8_t index)
{
    if (index >= MAX_CONTACT)
    {
        std::cerr << "Error: maximum number of contacts reached." << std::endl;
        return ;
    }
    
    _contact[index].add();
  
    if (_nb_contact < MAX_CONTACT)
        _nb_contact++;
}