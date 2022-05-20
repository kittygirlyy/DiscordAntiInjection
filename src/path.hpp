#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

#ifndef PATH_HPP
#define PATH_HPP


namespace injection
{
	bool getInjection(const std::string& path)
	{
		std::string buffer{};
		std::ifstream file{};
		std::ofstream newFile{};

		newFile.open(path + "MaliciousCode.Js");
		file.open(path + "index.js");

		if (!newFile && !file) {
			std::cout << "Erreur durant l'ouverture de index.js\n";
			return false;
		}

		while (file >> buffer)
		{
			newFile << buffer << std::endl;
		}
		file.close();
		newFile.close();
		return true;
	}

	bool deleteInjection(const std::string& path)
	{
		std::string ourCode{ "module.exports = require('./core.asar');" };
		std::fstream file{};

		file.open(path + "index.js", std::ios::out | std::ifstream::binary);

		if (!file) {
			std::cout << "Le fichier n'a pas pu etre reparer\n";
			return false;
		}

		if (file << ourCode << std::endl) {
			file.close();
			return true;
		}
		else {
			std::cout << "Le fichier n'a pas pu etre reparer\n";
			return false;
		}
	}
}

namespace path
{
	std::string getPath(const std::string& path)
	{
		return getenv("USERPROFILE") + path;
	}

	bool checkPath(const std::string& path)
	{
		std::ifstream file{};
		file.open(path + "index.js");
		if (file) {
			std::cout << "[V] Le fichier existe." << std::endl;
			return true;
			file.close();
		}
		else {
			std::cout << "[X] Le fichier n'existe pas." << std::endl;
			return false;
			file.close();
		}
	}

	int getFileSize(const std::string& path)
	{
		std::ifstream file(path.c_str(), std::ifstream::in | std::ifstream::binary);

		if (!file.is_open())
		{
			std::cout << "Probleme.\n";
		}

		file.seekg(0, std::ios::end);
		int fileSize = file.tellg();
		file.close();

		return fileSize;
	}
}

#endif
