#include "user.h"

User::User(std::string const& login,
	std::string const& password,
	int record,
	int maxTile,
	int score,
	int tiles) :login(login),
	password(password),
	record(record),
	maxTile(maxTile),
	score(score),
	tiles(tiles) {}

std::list<User> User::getUsers()
{
	std::list<User> users;
	std::ifstream input("source/user/userFiles/users.txt");
	User user;

	while (input >> user)
		users.push_back(user);

	return users;
}

std::string User::getLogin() const
{
	return login;
}

std::string User::getPassword() const
{
	return password;
}

int User::getRecord() const
{
	return record;
}

int User::getMaxTile() const
{
	return maxTile;
}

int User::getScore() const
{
	return score;
}

int User::getTiles() const
{
	return tiles;
}

void User::setRecord(int record) 
{
	this->record = record;
}

void User::setMaxTile(int maxTile) 
{
	this->maxTile = maxTile;
}

void User::setScore(int score)
{
	this->score = score;
}

void User::setTiles(int tiles)
{
	this->tiles = tiles;
}

std::istream& operator>>(std::istream& input, User& user)
{
	std::string login;
	std::string password;
	int record;
	int maxTile;
	input >> login >> password >> record >> maxTile;
	user = User(login, password, record, maxTile);
	return input;
}

std::ostream& operator<<(std::ostream& output, const User& user)
{
	output << user.getLogin() << " " << user.getPassword() << " " << user.getRecord() << " " << user.getMaxTile() << '\n';
	return output;
}