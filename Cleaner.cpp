#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <chrono> //sleep
#include <thread> //sleep
#include <string>


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
		std::cout << "Choose your Disk with League: (C, D, E, F, G): ";
		std::cin >> oper;

		switch (oper) {
		case 'c':
		case 'C':
			std::cout << "[-] Stopping all Riot Games processes..." << std::endl;
			std::system("taskkill -f -im League*");
			std::system("taskkill -f -im LeagueClient*");
			std::system("taskkill -f -im RiotClientServices*");
			std::system("taskkill -f -im riot*");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("cls");
			std::cout << "[-] Deleting all Riot/League logs..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("rd /s /q \"%userprofile%\\AppData\\Local\\Riot Games\"");
			std::system("rd /s /q \"C:\\ProgramData\\Riot Games\"");
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
			std::system("del \"C:\\Riot Games\\League of Legends\\debug.log\" /f /q");
			std::system("del \"C:\\Riot Games\\Riot Client\\UX\\natives_blob.bin\" /f /q");
			std::system("del \"C:\\Riot Games\\Riot Client\\UX\\icudtl.dat\" /f /q");
			std::system("del \"C:\\Riot Games\\Riot Client\\UX\\Plugins\\plugin-manifest.json\" /f /q");
			std::system("cls");
			std::cout << "[+] Done. HF" << std::endl;
			system("PAUSE");
			break;
		case 'd':
		case 'D':
			std::cout << "[-] Stopping all Riot Games processes..." << std::endl;
			std::system("taskkill -f -im League*");
			std::system("taskkill -f -im LeagueClient*");
			std::system("taskkill -f -im RiotClientServices*");
			std::system("taskkill -f -im riot*");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("cls");
			std::cout << "[-] Deleting all Riot/League logs..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("rd /s /q \"%userprofile%\\AppData\\Local\\Riot Games\"");
			std::system("rd /s /q \"D:\\ProgramData\\Riot Games\"");
			std::system("rd /s /q \"C:\\ProgramData\\Riot Games\"");
			std::system("rd /s /q \"D:\\Riot Games\\League of Legends\\Config\\Champions\"");
			std::system("rd /s /q \"D:\\Riot Games\\League of Legends\\Config\\Global\"");
			std::system("rd /s /q \"D:\\Riot Games\\League of Legends\\Logs\"");
			std::system("del \"D:\\ProgramData\\Riot Games\\machine.cfg\" /f /q");
			std::system("del \"D:\\Riot Games\\League of Legends\\Config\\input.ini\" /f /q");
			std::system("del \"D:\\Riot Games\\League of Legends\\Config\\ItemSets.json\" /f /q");
			std::system("del \"D:\\Riot Games\\League of Legends\\Config\\LCUAccountPreferences.yaml\" /f /q");
			std::system("del \"D:\\Riot Games\\League of Legends\\Config\\LCULocalPreferences.yaml\" /f /q");
			std::system("del \"D:\\Riot Games\\League of Legends\\Config\\LeagueClientSettings.yaml\" /f /q");
			std::system("del \"D:\\Riot Games\\League of Legends\\Config\\PerksPreferences.yaml\" /f /q");
			std::system("del \"D:\\Riot Games\\League of Legends\\debug.log\" /f /q");
			std::system("del \"D:\\Riot Games\\Riot Client\\UX\\natives_blob.bin\" /f /q");
			std::system("del \"D:\\Riot Games\\Riot Client\\UX\\icudtl.dat\" /f /q");
			std::system("del \"D:\\Riot Games\\Riot Client\\UX\\Plugins\\plugin-manifest.json\" /f /q");
			std::system("cls");
			std::cout << "[+] Done. HF" << std::endl;
			system("PAUSE");
			break;
		case 'e':
		case 'E':
			std::cout << "[-] Stopping all Riot Games processes..." << std::endl;
			std::system("taskkill -f -im League*");
			std::system("taskkill -f -im LeagueClient*");
			std::system("taskkill -f -im RiotClientServices*");
			std::system("taskkill -f -im riot*");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("cls");
			std::cout << "[-] Deleting all Riot/League logs..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("rd /s /q \"%userprofile%\\AppData\\Local\\Riot Games\"");
			std::system("rd /s /q \"E:\\ProgramData\\Riot Games\"");
			std::system("rd /s /q \"C:\\ProgramData\\Riot Games\"");
			std::system("rd /s /q \"E:\\Riot Games\\League of Legends\\Config\\Champions\"");
			std::system("rd /s /q \"E:\\Riot Games\\League of Legends\\Config\\Global\"");
			std::system("rd /s /q \"E:\\Riot Games\\League of Legends\\Logs\"");
			std::system("del \"E:\\ProgramData\\Riot Games\\machine.cfg\" /f /q");
			std::system("del \"E:\\Riot Games\\League of Legends\\Config\\input.ini\" /f /q");
			std::system("del \"E:\\Riot Games\\League of Legends\\Config\\ItemSets.json\" /f /q");
			std::system("del \"E:\\Riot Games\\League of Legends\\Config\\LCUAccountPreferences.yaml\" /f /q");
			std::system("del \"E:\\Riot Games\\League of Legends\\Config\\LCULocalPreferences.yaml\" /f /q");
			std::system("del \"E:\\Riot Games\\League of Legends\\Config\\LeagueClientSettings.yaml\" /f /q");
			std::system("del \"E:\\Riot Games\\League of Legends\\Config\\PerksPreferences.yaml\" /f /q");
			std::system("del \"E:\\Riot Games\\League of Legends\\debug.log\" /f /q");
			std::system("del \"E:\\Riot Games\\Riot Client\\UX\\natives_blob.bin\" /f /q");
			std::system("del \"E:\\Riot Games\\Riot Client\\UX\\icudtl.dat\" /f /q");
			std::system("del \"E:\\Riot Games\\Riot Client\\UX\\Plugins\\plugin-manifest.json\" /f /q");
			std::system("cls");
			std::cout << "[+] Done. HF" << std::endl;
			system("PAUSE");
			break;
		case 'f':
		case 'F':
			std::cout << "[-] Stopping all Riot Games processes..." << std::endl;
			std::system("taskkill -f -im League*");
			std::system("taskkill -f -im LeagueClient*");
			std::system("taskkill -f -im RiotClientServices*");
			std::system("taskkill -f -im riot*");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("cls");
			std::cout << "[-] Deleting all Riot/League logs..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("rd /s /q \"%userprofile%\\AppData\\Local\\Riot Games\"");
			std::system("rd /s /q \"F:\\ProgramData\\Riot Games\"");
			std::system("rd /s /q \"C:\\ProgramData\\Riot Games\"");
			std::system("rd /s /q \"F:\\Riot Games\\League of Legends\\Config\\Champions\"");
			std::system("rd /s /q \"F:\\Riot Games\\League of Legends\\Config\\Global\"");
			std::system("rd /s /q \"F:\\Riot Games\\League of Legends\\Logs\"");
			std::system("del \"F:\\ProgramData\\Riot Games\\machine.cfg\" /f /q");
			std::system("del \"F:\\Riot Games\\League of Legends\\Config\\input.ini\" /f /q");
			std::system("del \"F:\\Riot Games\\League of Legends\\Config\\ItemSets.json\" /f /q");
			std::system("del \"F:\\Riot Games\\League of Legends\\Config\\LCUAccountPreferences.yaml\" /f /q");
			std::system("del \"F:\\Riot Games\\League of Legends\\Config\\LCULocalPreferences.yaml\" /f /q");
			std::system("del \"F:\\Riot Games\\League of Legends\\Config\\LeagueClientSettings.yaml\" /f /q");
			std::system("del \"F:\\Riot Games\\League of Legends\\Config\\PerksPreferences.yaml\" /f /q");
			std::system("del \"F:\\Riot Games\\League of Legends\\debug.log\" /f /q");
			std::system("del \"F:\\Riot Games\\Riot Client\\UX\\natives_blob.bin\" /f /q");
			std::system("del \"F:\\Riot Games\\Riot Client\\UX\\icudtl.dat\" /f /q");
			std::system("del \"F:\\Riot Games\\Riot Client\\UX\\Plugins\\plugin-manifest.json\" /f /q");
			std::system("cls");
			std::cout << "[+] Done. HF" << std::endl;
			system("PAUSE");
			break;
		case 'g':
		case 'G':
			std::cout << "[-] Stopping all Riot Games processes..." << std::endl;
			std::system("taskkill -f -im League*");
			std::system("taskkill -f -im LeagueClient*");
			std::system("taskkill -f -im RiotClientServices*");
			std::system("taskkill -f -im riot*");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("cls");
			std::cout << "[-] Deleting all Riot/League logs..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::system("rd /s /q \"%userprofile%\\AppData\\Local\\Riot Games\"");
			std::system("rd /s /q \"G:\\ProgramData\\Riot Games\"");
			std::system("rd /s /q \"C:\\ProgramData\\Riot Games\"");
			std::system("rd /s /q \"G:\\Riot Games\\League of Legends\\Config\\Champions\"");
			std::system("rd /s /q \"G:\\Riot Games\\League of Legends\\Config\\Global\"");
			std::system("rd /s /q \"G:\\Riot Games\\League of Legends\\Logs\"");
			std::system("del \"G:\\ProgramData\\Riot Games\\machine.cfg\" /f /q");
			std::system("del \"G:\\Riot Games\\League of Legends\\Config\\input.ini\" /f /q");
			std::system("del \"G:\\Riot Games\\League of Legends\\Config\\ItemSets.json\" /f /q");
			std::system("del \"G:\\Riot Games\\League of Legends\\Config\\LCUAccountPreferences.yaml\" /f /q");
			std::system("del \"G:\\Riot Games\\League of Legends\\Config\\LCULocalPreferences.yaml\" /f /q");
			std::system("del \"G:\\Riot Games\\League of Legends\\Config\\LeagueClientSettings.yaml\" /f /q");
			std::system("del \"G:\\Riot Games\\League of Legends\\Config\\PerksPreferences.yaml\" /f /q");
			std::system("del \"G:\\Riot Games\\League of Legends\\debug.log\" /f /q");
			std::system("del \"G:\\Riot Games\\Riot Client\\UX\\natives_blob.bin\" /f /q");
			std::system("del \"G:\\Riot Games\\Riot Client\\UX\\icudtl.dat\" /f /q");
			std::system("del \"G:\\Riot Games\\Riot Client\\UX\\Plugins\\plugin-manifest.json\" /f /q");
			std::system("cls");
			std::cout << "[+] Done. HF" << std::endl;
			system("PAUSE");
			break;

		default:
			std::cout << "I'm sorry I'm not support this disk yet =( '\n'";
			system("PAUSE");
			break;
		}
	return 0;
}