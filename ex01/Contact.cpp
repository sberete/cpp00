#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void Contact::add()
{
	std::cout << "First name" << std::endl;
	std::cin >> firstname;
	std::cout << "Last name" << std::endl;
	std::cin >> lastname;
	std::cout << "Nickname" << std::endl;
	std::cin >> nickname;
	std::cout << "Phone number" << std::endl;
	std::cin >> phonenumber;
	std::cout << "Darkest secret" << std::endl;
	std::cin >> darkestsecret;
}

std::string Contact::getFirstname() const
{
	return (this->firstname);
}

std::string Contact::getLastname() const
{
	return (this->lastname);
}

std::string Contact::getNickname() const
{
	return (this->nickname);
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
