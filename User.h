#pragma once
#include <string>

class User
{
private:
	const std::string login_;
	std::string password_;
	std::string name_;

public:
	User(const std::string& login, const std::string& password)
		:login_(login), password_(password) {}
	const std::string& getUserByLogin()  const  { return login_; }

	const std::string& getUserByPassword() const { return password_; }
	void setUserPassword(const std::string& password) { password_ = password; }

	const std::string& getUserByName() const { return name_; }
	void setUserName(const std::string& name) { name_ = name; }

};