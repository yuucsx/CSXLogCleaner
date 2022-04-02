#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <chrono> //sleep
#include <thread> //sleep

int main()
{
	system("color 09");

		std::cout << R"(

  ______    _   _    _ _                   ______ _                              
 / _____)  | | \ \  / / |                 / _____) |                             
| /         \ \ \ \/ /| |      ___   ____| /     | | ____ ____ ____   ____  ____ 
| |          \ \ )  ( | |     / _ \ / _  | |     | |/ _  ) _  |  _ \ / _  )/ ___)
| \_____ _____) ) /\ \| |____| |_| ( ( | | \_____| ( (/ ( ( | | | | ( (/ /| |    
 \______|______/_/  \_\_______)___/ \_|| |\______)_|\____)_||_|_| |_|\____)_|    by: .Yuu#0001
                                   (_____|                                       

)" << '\n';
	std::cout << "Log Cleaner for Riot League of Legends to prevent automatic hwid bans." << std::endl;
	system("PAUSE");
	std::cout << "[-] Stopping all Riot Games processes..." << std::endl;
	std::system("taskkill -f -im riot*");
	std::system("taskkill -f -im league*");
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "[-] Deleting all Riot/League logs..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::system("rd /s /q \"%userprofile%\\AppData\\Local\\Riot Games\"");
	std::system("rd /s /q \"C:\\Riot Games\\League of Legends\\Config\\Champions\"");
	std::system("rd /s /q \"C:\\Riot Games\\League of Legends\\Config\\Global\"");
	std::system("rd /s /q \"C:\\Riot Games\\League of Legends\\Logs\"");
	std::system("del \"C:\\ProgramData\\Riot Games\\machine.cfg\" /f /q");
	std::system("del \"C:\\Riot Games\\League of Legends\\Config\\input.ini\" /f /q");
	std::system("del \"C:\\Riot Games\\League of Legends\\Config\\ItemSets.json\" /f /q");
	std::system("del \"C:\\Riot Games\\League of Legends\\Config\\LCUAccountPreferences.yaml\" /f /q");
	std::system("del \"C:\\Riot Games\\League of Legends\\Config\\LCULocalPreferences.yaml\" /f /q");
	std::system("del \"C:\\Riot Games\\League of Legends\\Config\\LeagueClientSettings.yaml\" /f /q");
	std::system("del \"C:\\Riot Games\\League of Legends\\Config\\PerksPreferences.yaml\" /f /q");
	std::system("cls");
	std::cout << "[+] Done. HF" << std::endl;
	system("PAUSE");
	return 0;
}