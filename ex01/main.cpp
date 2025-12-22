#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string str;
    uint8_t i = 0;

    for(;;)
    {
        std::cout << "add, search and exit" << std::endl;
        std::cin >> str;
        if (str.compare("add") == 0)
            pb.addContactintoPhoneBook(i++);
        if (str.compare("search") == 0)
            pb.search();
        if (str.compare("exit") == 0)
            return(0);
        if (i >= MAX_CONTACT){i = 0;}
    }
}