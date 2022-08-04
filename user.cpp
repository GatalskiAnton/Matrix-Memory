#include "user.h"

std::istream& operator>>(std::istream& input, User& user)
{
	std::string login;
	std::string password;
	int record;
	int maxTile;
	input >> login >> password >> record >> maxTile;
	user = User(login,password, record, maxTile);
	return input;
}

std::ostream& operator<<(std::ostream& output, const User& user)
{
	output << user.getLogin() << " " << user.getPassword() << " " << user.getRecord() << " " << user.getMaxTile() << '\n';
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

int User::getRecord() const
{
	return record_;
}

int User::getMaxTile() const
{
	return maxTile_;
}

void User::setRecord(int record) 
{
	record_ = record;
}

void User::setMaxTile(int maxTile) 
{
	maxTile_ = maxTile;
}
