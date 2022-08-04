#pragma once
#include <string>
#include <list>
#include <fstream>

class User
{
public:
	User() = default;
	User(std::string const& login, std::string const& password, int const& record = 0, int maxTile = 0) :login_(login), password_(password), record_(record), maxTile_(maxTile) {};
	~User() = default;
	static std::list<User> getUsers();
	std::string getLogin() const;
	std::string getPassword() const;
	int getRecord() const;
	int getMaxTile() const;
	void setRecord(int record) ;
	void setMaxTile(int maxTile) ;
private:
	std::string login_;
	std::string password_;
	int record_;
	int maxTile_;
};
std::istream& operator>>(std::istream&, User&);
std::ostream& operator<<(std::ostream&, const User&);