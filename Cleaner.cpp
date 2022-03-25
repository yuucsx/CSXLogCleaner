#include <iostream>
#include <filesystem>

int main()
{
	//std::system("rmdir C:\\Users\\yukki\\AppData\\Local\\Riot Games\\League of Legends\\Logs");
	//return 0;

	system("color 09");
	std::cout << "Detailed automatic league log cleaner." << std::endl << "make sure your league is installed on disk C:, and your league client is closed." << std::endl << "press any button to run" << std::endl;
	system("PAUSE");
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
	system("color 09");
	system("color 09");
	return 0;
}