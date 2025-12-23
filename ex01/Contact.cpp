#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void Contact::add()
{
    std::cout << "Enter first name: ";
    std::cin >> _firstname;
    std::cout << "Enter last name: ";
    std::cin >> _lastname;
    std::cout << "Enter nickname: ";
    std::cin >> _nickname;
    std::cout << "Enter phone number: ";
    std::cin >> _phonenumber;
    std::cout << "Enter darkest secret: ";
    std::cin >> _darkestsecret;
}

std::string Contact::getFirstname() const
{
	return (this->_firstname);
}

std::string Contact::getLastname() const
{
	return (this->_lastname);
}

std::string Contact::getNickname() const
{
	return (this->_nickname);
}

static std::string trunc_string(std::string str)
{
	std::string buffer = str;
	std::size_t len = buffer.size() - 9;
	buffer.replace(9, len, ".");
	return (buffer);
}

static std::string extand_string(std::string str)
{
	std::string buffer = str;
	std::size_t len = 10 - buffer.size();
	buffer.insert(0, len, ' ');
	return (buffer);
}

static std::string formatForColumn(std::string str)
{
	if (str.size() > 10)
		return (trunc_string(str));
	else if (str.size() < 10)
		return (extand_string(str));
	else
		return (str);
}

std::string Contact::getFormattedValue(O_flag flag)
{
	switch (flag)
	{
		case FIRSTNAME:
			return (formatForColumn(getFirstname()));
		case LASTNAME:
			return (formatForColumn(getLastname()));
		case NICKNAME:
			return (formatForColumn(getNickname()));
		default:
			return ("");
	}
}
