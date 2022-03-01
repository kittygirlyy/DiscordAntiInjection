#include <iostream>
#include <windows.h>
#include "path.hpp"

int main()
{
	#if _DEBUG
	std::cout << "DEBUG";
	return 0;
	#endif

	std::string PATH{"\\AppData\\Local\\Discord\\app-1.0.9004\\modules\\discord_desktop_core-1\\discord_desktop_core\\"};
	std::string password{}, newPassword{}, token{};

	PATH = path::getPath(PATH);
	while(true) {
		if (path::checkPath(PATH)) {
			if (path::getFileSize(PATH + "index.js") < 42) {
				std::cout << "Le fichier n'est pas modifier.\n";
			} else {
				std::cout << "Le fichier est modifier.\n";
				if (injection::getInjection(PATH)) {
					std::cout << "Le code est sauvegarder...\n";
					if (injection::deleteInjection(PATH)) {
						std::cout << "L'injection est retirer...\n";
						return 0;
					} else {
						return EXIT_FAILURE;
					}
				} else {
					return EXIT_FAILURE;
				}
			}
		} else {
			std::cout << "Veuillez installer discord...\n";
		}
		std::cout << "Relancement...\n";
		Sleep(3000);
	}
}