#ifndef CONTACT_HPP
    #define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;

    public:
        enum O_flag
        {
            FIRSTNAME,
            LASTNAME,
            NICKNAME,
        };
        std::string getFirstname() const;
        std::string getLastname() const;
        std::string getNickname() const;
        std::string getFormattedValue(O_flag);
        void add();
        Contact();
        ~Contact();
}; 

#endif