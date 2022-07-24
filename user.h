#pragma once
#include <string>
#include <list>
#include <fstream>

class User
{
public:
	User() = default;
	User(std::string const& login, std::string const& password) :login_(login), password_(password) {};
	~User() = default;
	static std::list<User> getUsers();
	std::string getLogin() const;
	std::string getPassword() const;
private:
	std::string login_;
	std::string password_;
};
std::istream& operator>>(std::istream&, User&);