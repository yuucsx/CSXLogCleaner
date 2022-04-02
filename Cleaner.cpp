#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <chrono> //sleep
#include <thread> //sleep

int main()
{
	system("color 09");
	std::cout << "Log Cleaner for Riot League of Legends to prevent automatic hwid bans." << std::endl << "press any button to run" << std::endl;
	system("PAUSE");
	std::system("taskkill -f -im riot*");
	std::system("taskkill -f -im league*");
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
	std::cout << "Done. HF" << std::endl << "Made by: .Yuu#0001" << std::endl;
	system("PAUSE");
	return 0;
}