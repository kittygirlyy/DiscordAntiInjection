#include <string>

#ifndef DISCORDREQUEST_HPP
#define DISCORDREQUEST_HPP


class DiscordRequest {

private:

	std::string token{};
	std::string password{};
	std::string newPassword{};

public:

	DiscordRequest(std::string qToken = "ValidToken", std::string qPassword = "ValidPassword", std::string qNewPassword = "ValidNewPassword");

	bool changePassword();
	friend void initCurl();
};


#endif

