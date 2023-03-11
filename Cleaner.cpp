#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <chrono> //sleep
#include <thread> //sleep
#include <string>

const std::string LOG_PATH = "%userprofile%\\AppData\\Local\\Riot Games";
const std::string PROGRAM_DATA_PATH = "ProgramData\\Riot Games";
const std::string CONFIG_CHAMPION_PATH = "Riot Games\\League of Legends\\Config\\Champions";
const std::string CONFIG_GLOBAL_PATH = "Riot Games\\League of Legends\\Config\\Global";
const std::string LOGS_PATH = "Riot Games\\League of Legends\\Logs";
const std::string MACHINE_CFG_PATH = "ProgramData\\Riot Games\\machine.cfg";
const std::string INPUT_INI_PATH = "Riot Games\\League of Legends\\Config\\input.ini";
const std::string ITEMSET_JSON_PATH = "Riot Games\\League of Legends\\Config\\ItemSets.json";
const std::string LCU_ACCOUNT_PATH = "Riot Games\\League of Legends\\Config\\LCUAccountPreferences.yaml";
const std::string LCU_LOCAL_PATH = "Riot Games\\League of Legends\\Config\\LCULocalPreferences.yaml";
const std::string LEAGUE_CLIENT_SETTINGS_PATH = "Riot Games\\League of Legends\\Config\\LeagueClientSettings.yaml";
const std::string PERKS_PATH = "Riot Games\\League of Legends\\Config\\PerksPreferences.yaml";
const std::string DEBUG_LOG_PATH = "Riot Games\\League of Legends\\debug.log";
const std::string NATIVE_BLOB_PATH = "Riot Games\\Riot Client\\UX\\natives_blob.bin";
const std::string ICUDTL_PATH = "Riot Games\\Riot Client\\UX\\icudtl.dat";
const std::string PLUGIN_MANIFEST_PATH = "Riot Games\\Riot Client\\UX\\Plugins\\plugin-manifest.json";

void cleanLogs(const std::string& diskLetter) {
	std::cout << "[-] Stopping all Riot Games processes..." << std::endl;
	std::system("taskkill -f -im League*");
	std::system("taskkill -f -im LeagueClient*");
	std::system("taskkill -f -im RiotClientServices*");
	std::system("taskkill -f -im riot*");
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::system("cls");
	std::cout << "[-] Deleting all Riot/League logs..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::system(("rd /s /q \"" + LOG_PATH + "\"").c_str());
	std::system(("rd /s /q \"" + diskLetter + ":\\" + PROGRAM_DATA_PATH + "\"").c_str());
	std::system(("rd /s /q \"" + diskLetter + ":\\" + CONFIG_CHAMPION_PATH + "\"").c_str());
	std::system(("rd /s /q \"" + diskLetter + ":\\" + CONFIG_GLOBAL_PATH + "\"").c_str());
	std::system(("rd /s /q \"" + diskLetter + ":\\" + LOGS_PATH + "\"").c_str());
	std::system(("del \"" + diskLetter + ":\\" + MACHINE_CFG_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + INPUT_INI_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + ITEMSET_JSON_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + LCU_ACCOUNT_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + LCU_LOCAL_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + LEAGUE_CLIENT_SETTINGS_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + PERKS_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + DEBUG_LOG_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + NATIVE_BLOB_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + ICUDTL_PATH + "\" /f /q").c_str());
	std::system(("del \"" + diskLetter + ":\\" + PLUGIN_MANIFEST_PATH + "\" /f /q").c_str());
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
	std::cout << "Choose your Disk with League: (C, D, E, F, G): ";
	std::cin >> oper;
	std::string diskLetter = std::string(1, oper);

	switch (oper) {
	case 'c':
	case 'C':
	case 'd':
	case 'D':
	case 'e':
	case 'E':
	case 'f':
	case 'F':
	case 'g':
	case 'G':
		cleanLogs(diskLetter);
		system("PAUSE");
		break;

	default:
		std::cout << "I'm sorry I'm not support this disk yet =( '\n'";
		system("PAUSE");
		break;
	}
	return 0;
}