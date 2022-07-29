#include "user.h"

std::istream& operator>>(std::istream& input, User& user)
{
	std::string login, password;
	input >> login >> password;
	user = User(login,password);
	return input;
}

std::ostream& operator<<(std::ostream& output, const User& user)
{
	output << user.getLogin() << " " << user.getPassword() << '\n';
	return output;
}

std::list<User> User::getUsers()
{
	std::list<User> users;
	std::ifstream input("files/users.txt");
	User user;

	while (input >> user)
		users.push_back(user);

	return users;
}

std::string User::getLogin() const
{
	return login_;
}

std::string User::getPassword() const
{
	return password_;
}