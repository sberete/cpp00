#include "PhoneBook.hpp"
#include <limits>

int main()
{
    PhoneBook pb;
    std::string str;
    uint8_t i = 0;

    for(;;)
    {
        std::cout << "Available commands: ADD | SEARCH | EXIT" << std::endl;
        if (!std::getline(std::cin, str)) 
        {
            std::cout << "End of file detected. Program terminated." << std::endl;
            break;
        }
        if (str.compare("ADD") == 0)
            pb.addContactintoPhoneBook(i++);
        if (str.compare("SEARCH") == 0)
            pb.search();
        if (str.compare("EXIT") == 0)
            return(0);
        if (i >= MAX_CONTACT){i = 0;}
    }
}