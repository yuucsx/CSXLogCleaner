#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>

#define COLOR_RED     12
#define COLOR_GREEN   10
#define COLOR_BLUE    9
#define COLOR_CYAN    11
#define COLOR_WHITE   15
#define COLOR_YELLOW  14

void setColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

std::string expandEnvironmentVariables(const std::string& str) {
    char expanded[MAX_PATH];
    ExpandEnvironmentStringsA(str.c_str(), expanded, MAX_PATH);
    return std::string(expanded);
}

const std::vector<std::string> PATHS = {
    "%userprofile%\\AppData\\Local\\Riot Games",
    "%ProgramData%\\Riot Games",
    "%USERPROFILE%\\Documents\\League of Legends\\Highlights",
    "Riot Games\\League of Legends\\Config",
    "Riot Games\\League of Legends\\Config\\Champions",
    "Riot Games\\League of Legends\\Config\\Global",
    "Riot Games\\League of Legends\\Logs",
    "Riot Games\\League of Legends\\GPUCache",
    "Riot Games\\League of Legends\\Screenshots",
    "Riot Games\\League of Legends\\Cache",
    "Riot Games\\League of Legends\\LCCache",
    "%ProgramFiles%\\Riot Vanguard\\Logs",
    "%ProgramFiles(x86)%\\Riot Vanguard\\Logs",
    "C:\\Windows\\Prefetch\\LEAGUE*.*",
    "C:\\Windows\\Prefetch\\RIOT*.*"
};

// Drives to check
const std::vector<std::string> DRIVES = { "C", "D", "E" };

void stopProcesses() {
    std::vector<std::string> processes = {
        "LeagueClientUx.exe", "League of Legends.exe", "RiotClientServices.exe",
        "RiotClientUxRender.exe", "LeagueClient.exe", "LeagueCrashHandler.exe"
    };

    setColor(COLOR_YELLOW);
    std::cout << "[-] Stopping Riot Games & League of Legends processes..." << std::endl;
    setColor(COLOR_WHITE);

    for (const auto& process : processes) {
        std::string command = "taskkill /F /IM " + process + " /T >nul 2>&1";
        std::system(command.c_str());
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void cleanLogs(bool deleteConfig) {
    stopProcesses();
    std::system("cls");

    setColor(COLOR_YELLOW);
    std::cout << "[-] Deleting all Riot/League logs and caches..." << std::endl;
    setColor(COLOR_WHITE);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    for (const auto& drive : DRIVES) {
        for (const auto& path : PATHS) {
            std::string fullPath = drive + ":\\" + path;
            fullPath = expandEnvironmentVariables(fullPath);

            if (std::filesystem::exists(fullPath)) {
                setColor(COLOR_CYAN);
                std::cout << "[-] Deleting: " << fullPath << std::endl;
                setColor(COLOR_WHITE);
                try {
                    if (std::filesystem::is_directory(fullPath)) {
                        std::filesystem::remove_all(fullPath);
                    }
                    else {
                        std::filesystem::remove(fullPath);
                    }
                }
                catch (const std::filesystem::filesystem_error& e) {
                    setColor(COLOR_RED);
                    std::cerr << "[!] Error deleting " << fullPath << ": " << e.what() << std::endl;
                    setColor(COLOR_WHITE);
                }
            }
        }

        if (deleteConfig) {
            std::string configPath = drive + ":\\Riot Games\\League of Legends\\Config";
            if (std::filesystem::exists(configPath)) {
                setColor(COLOR_YELLOW);
                std::cout << "[-] Deleting Config files in: " << configPath << std::endl;
                setColor(COLOR_WHITE);
                try {
                    std::filesystem::remove_all(configPath);
                }
                catch (const std::filesystem::filesystem_error& e) {
                    setColor(COLOR_RED);
                    std::cerr << "[!] Error deleting " << configPath << ": " << e.what() << std::endl;
                    setColor(COLOR_WHITE);
                }
            }
        }
    }

    std::system("cls");
    setColor(COLOR_GREEN);
    std::cout << "[+] Logs and caches have been cleaned." << (deleteConfig ? " Config files were also deleted." : " Config files were not deleted.") << std::endl;
    setColor(COLOR_WHITE);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::system("cls");

    setColor(COLOR_BLUE);
    std::cout << R"(

  ______    _   _    _ _                   ______ _                              
 / _____)  | | \ \  / / |                 / _____) |                             
| /         \ \ \ \/ /| |      ___   ____| /     | | ____ ____ ____   ____  ____ 
| |          \ \ )  ( | |     / _ \ / _  | |     | |/ _  ) _  |  _ \ / _  )/ ___)
| \_____ _____) ) /\ \| |____| |_| ( ( | | \_____| ( (/ ( ( | | | | ( (/ /| |    
 \______|______/_/  \_\_______)___/ \_|| |\______)_|\____)_||_|_| |_|\____)_|    by: yuusz
                                   (_____|                                       

)" << '\n';
    setColor(COLOR_WHITE);

    std::cout << "Log Cleaner for Riot Games' League of Legends to prevent automatic HWID bans." << std::endl;

    char choice;
    std::cout << "Do you want to delete config files? (Y/N): ";
    std::cin >> choice;
    choice = std::toupper(choice);

    if (choice == 'Y') {
        cleanLogs(true);
    }
    else if (choice == 'N') {
        cleanLogs(false);
    }
    else {
        setColor(COLOR_RED);
        std::cout << "[!] Invalid option. Exiting..." << std::endl;
        setColor(COLOR_WHITE);
    }

    system("PAUSE");
    return 0;
}
