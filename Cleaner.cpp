#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>
#include <vector>

// Constants for file paths
const std::vector<std::string> PATHS = {
	"%userprofile%\\AppData\\Local\\Riot Games",
	"ProgramData\\Riot Games",
	"Riot Games\\League of Legends\\Config\\Champions",
	"Riot Games\\League of Legends\\Config\\Global",
	"Riot Games\\League of Legends\\Logs",
	"ProgramData\\Riot Games\\machine.cfg",
	"Riot Games\\League of Legends\\Config\\input.ini",
	"Riot Games\\League of Legends\\Config\\ItemSets.json",
	"Riot Games\\League of Legends\\Config\\LCUAccountPreferences.yaml",
	"Riot Games\\League of Legends\\Config\\LCULocalPreferences.yaml",
	"Riot Games\\League of Legends\\Config\\LeagueClientSettings.yaml",
	"Riot Games\\League of Legends\\Config\\PerksPreferences.yaml",
	"Riot Games\\League of Legends\\debug.log",
	"Riot Games\\Riot Client\\UX\\natives_blob.bin",
	"Riot Games\\Riot Client\\UX\\snapshot_blob.bin",
	"Riot Games\\Riot Client\\UX\\v8_context_snapshot.bin",
	"Riot Games\\Riot Client\\UX\\icudtl.dat",
	"Riot Games\\Riot Client\\UX\\Plugins\\plugin-manifest.json"
};

void stopProcesses() {
	std::vector<std::string> processes = {
		"League*", "LeagueClient*", "RiotClientServices*", "riot*"
	};

	std::cout << "[-] Stopping Riot Games & League of Legends processes..." << std::endl;
	for (const auto& process : processes) {
		std::string command = "taskkill /F /IM " + process;
		std::system(command.c_str());
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void cleanLogs(const std::string& diskLetter) {
	// Normalize diskLetter to uppercase
	std::string normalizedDiskLetter = diskLetter;
	std::transform(normalizedDiskLetter.begin(), normalizedDiskLetter.end(), normalizedDiskLetter.begin(), ::toupper);

	stopProcesses();
	std::system("cls");
	std::cout << "[-] Deleting all Riot/League logs..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	for (const auto& path : PATHS) {
		std::string fullPath = normalizedDiskLetter + ":\\" + path;
		if (std::filesystem::exists(fullPath)) {
			if (std::filesystem::is_directory(fullPath)) {
				std::system(("rd /s /q \"" + fullPath + "\"").c_str());
			}
			else {
				std::system(("del \"" + fullPath + "\" /f /q").c_str());
			}
		}
	}

	std::system("cls");
	std::cout << "[+] Done. HF" << std::endl;
}

int main()
{
	system("color 09");

	std::cout << R"(

  ______    _   _    _ _                   ______ _                              
 / _____)  | | \ \  / / |                 / _____) |                             
| /         \ \ \ \/ /| |      ___   ____| /     | | ____ ____ ____   ____  ____ 
| |          \ \ )  ( | |     / _ \ / _  | |     | |/ _  ) _  |  _ \ / _  )/ ___)
| \_____ _____) ) /\ \| |____| |_| ( ( | | \_____| ( (/ ( ( | | | | ( (/ /| |    
 \______|______/_/  \_\_______)___/ \_|| |\______)_|\____)_||_|_| |_|\____)_|    by: Misa#0003
                                   (_____|                                       

)" << '\n';

	char oper;
	std::cout << "Log Cleaner for Riot League of Legends to prevent automatic hwid bans." << std::endl;
	std::cout << "Choose your Disk with League: ";
	std::cin >> oper;
	std::string diskLetter = std::string(1, oper);

	// Check if the disk letter is alphabetic and convert to uppercase
	if (std::isalpha(oper)) {
		diskLetter = std::toupper(oper);
		cleanLogs(diskLetter);
		system("PAUSE");
	}
	else {
		std::cout << "Invalid disk letter. Please enter a letter (A-Z)." << std::endl;
		system("PAUSE");
	}

	return 0;
}