#include <iostream>
#include <curl/curl.h>
#include "discordRequest.hpp"

DiscordRequest::DiscordRequest(std::string qToken, std::string qPassword, std::string qNewPassword)
{
	token = qToken;
	password = qPassword;
	newPassword = qNewPassword;
}

bool DiscordRequest::changePassword()
{
	if (token.length() > 5)
		return true;
}

void initCurl()
{

	std::string discordApi{ "https://discord.com/" };
	CURL* init = curl_easy_init();
}