#pragma once

#include <string>
#include <list>
#include <fstream>

class User
{
public:
	User() = default;
	User(std::string const& login, std::string const& password, int  record = 0, int maxTile = 0, int score = 0 , int tiles = 0) :login_(login), password_(password), record_(record), maxTile_(maxTile),score_(score),tiles_(tiles) {};
	~User() = default;
	static std::list<User> getUsers();
	std::string getLogin() const;
	std::string getPassword() const;
	int getRecord() const;
	int getMaxTile() const;
	int getScore() const;
	int getTiles() const;
	void setRecord(int record);
	void setMaxTile(int maxTile);
	void setScore(int score);
	void setTiles(int tiles);
private:
	std::string login_;
	std::string password_;
	int record_;
	int maxTile_;
	int score_;
	int tiles_;
};

std::istream& operator>>(std::istream&, User&);
std::ostream& operator<<(std::ostream&, const User&);