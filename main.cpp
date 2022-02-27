#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <fstream>

std::string getPath(std::string path)
{
	return getenv("USERPROFILE") + path;
}

bool presenceFile(std::string path)
{
	std::ifstream file;
	file.open(path + "index.js");
	if (file) {
		std::cout << "Le fichier existe." << std::endl;
		return true;
	} else {
		std::cout << "Le fichier n'existe pas." << std::endl;
		return false;
	}
}

int getFileSize(const std::string& fileName)
{
	std::ifstream file(fileName.c_str(), std::ifstream::in | std::ifstream::binary);

	if (!file.is_open())
	{
		std::cout << "Probleme\n";
	}

	file.seekg(0, std::ios::end);
	int fileSize = file.tellg();
	file.close();

	return fileSize;
}


int main()
{
	std::string PATH{"\\AppData\\Local\\Discord\\app-1.0.9004\\modules\\discord_desktop_core-1\\discord_desktop_core\\"};

	PATH = getPath(PATH);
	while (true) {
		if (presenceFile(PATH)) {
			if (getFileSize(PATH + "index.js") < 42) {
				std::cout << "Le fichier n'est pas modifier.\n";
			} else {
				std::cout << "Le fichier est modifier.\n";
			}
		} else {
			std::cout << "Veuillez attendre...\n";
		}
		std::cout << "Relancement...\n";
		Sleep(3000);
	}
}