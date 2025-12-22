#include "PhoneBook.hpp"

PhoneBook::PhoneBook()  {_nb_contact = 0;}

PhoneBook::~PhoneBook(){}

void PhoneBook::search()
{
    if (!_nb_contact)
        return ;
    std::cout << "index" << " | "<< " firstname" << " | " << " last_name" << " | " << "  nickname" << std::endl;
    for(uint8_t i = 0; i < _nb_contact; i++)
        std::cout << "    " << i + 1 << " | " << _contact[i].getFormattedValue(Contact::FIRSTNAME) << " | " << _contact[i].getFormattedValue(Contact::LASTNAME) << " | " << _contact[i].getFormattedValue(Contact::NICKNAME) << std::endl;
}

void PhoneBook::addContactintoPhoneBook(uint8_t index)
{
    if (index >= MAX_CONTACT)
        std::runtime_error(" << "" << std::endl");
    
    _contact[index].add();
  
    if (_nb_contact < MAX_CONTACT)
        _nb_contact++;
}