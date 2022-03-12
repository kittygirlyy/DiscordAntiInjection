#include <iostream>
#include <windows.h>
#include "path.hpp"
#include "discordRequest.hpp"

void DEBUG()
{
#if _DEBUG
	std::cout << "DEBUG";
	return 0;
#endif
}

int main()
{
	DEBUG();
	std::string PATH{"\\AppData\\Local\\Discord\\app-1.0.9004\\modules\\discord_desktop_core-2\\discord_desktop_core\\"};
	std::string password{}, newPassword{}, token{};

	//std::cin.ignore(256, '\n') >> token;
	//std::cin.ignore(256, '\n') >> password;
	//std::cin.ignore(256, '\n') >> newPassword;
	//DiscordRequest firstReq{token, password, newPassword};
	//std::cout << firstReq.changePassword();
	PATH = path::getPath(PATH);
	while(true) {
		if (path::checkPath(PATH)) {
			if (path::getFileSize(PATH + "index.js") < 42) {
				std::cout << "[X] Le fichier n'est pas modifier.\n";
			} else {
				std::cout << "[V] Le fichier est modifier.\n";
				if (injection::getInjection(PATH)) {
					std::cout  <<"[V] Le code est sauvegarder...\n";
					if (injection::deleteInjection(PATH)) {
						std::cout << "[V] L'injection est retirer...\n";
						return EXIT_SUCCESS;
					} else {
						return EXIT_FAILURE;
					}
				} else {
					return EXIT_FAILURE;
				}
			}
		} else {
			std::cout << "[X] Veuillez installer discord...\n";
		}
		std::cout << "[+] Relancement...\n==================\n";
		Sleep(3000);
	}
}