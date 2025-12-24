#ifndef PHONEBOOK_HPP
    #define PHONEBOOK_HPP


#include "Contact.hpp"
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iomanip> 

#define MAX_CONTACT 8

class PhoneBook
{
    public:
        void search();
        PhoneBook();
        ~PhoneBook();
        void addContactintoPhoneBook(uint8_t index);

    private:
        Contact _contact[MAX_CONTACT];
        uint8_t _nb_contact;
};

#endif