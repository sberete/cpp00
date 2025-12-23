#ifndef CONTACT_HPP
    #define CONTACT_HPP

#include <iostream>

class Contact
{
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

    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phonenumber;
        std::string _darkestsecret;
}; 

#endif