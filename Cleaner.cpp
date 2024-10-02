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
    "Riot Games\\League of Legends\\Config\\Champions",
    "Riot Games\\League of Legends\\Config\\Global",
    "Riot Games\\League of Legends\\Logs",
    "Riot Games\\League of Legends\\LCCache",
    "Riot Games\\League of Legends\\GPUCache",
    "%ProgramFiles%\\Riot Vanguard\\Logs",
    "%ProgramFiles(x86)%\\Riot Vanguard\\Logs",
    "%ProgramData%\\Riot Games\\machine.cfg",
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

// Drives to check
const std::vector<std::string> DRIVES = { "C", "D", "E" };

void stopProcesses() {
    std::vector<std::string> processes = {
        "LeagueClientUx.exe",
        "League of Legends.exe",
        "RiotClientServices.exe",
        "RiotClientUxRender.exe",
        "LeagueClient.exe",
        "LeagueCrashHandler.exe",
        "vgtray.exe",
        "League*", "LeagueClient*", "RiotClientServices*", "riot*"
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

void cleanLogs() {
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
    }

    for (const auto& drive : DRIVES) {
        std::string prefetchPath = drive + ":\\Windows\\Prefetch";
        if (std::filesystem::exists(prefetchPath)) {
            setColor(COLOR_YELLOW);
            std::cout << "[-] Deleting Prefetch files in " << prefetchPath << std::endl;
            setColor(COLOR_WHITE);
            for (const auto& entry : std::filesystem::directory_iterator(prefetchPath)) {
                std::string filename = entry.path().filename().string();
                if (filename.find("LEAGUE") != std::string::npos || filename.find("RIOT") != std::string::npos) {
                    try {
                        std::filesystem::remove(entry.path());
                        setColor(COLOR_CYAN);
                        std::cout << "[-] Deleted: " << entry.path().string() << std::endl;
                        setColor(COLOR_WHITE);
                    }
                    catch (const std::filesystem::filesystem_error& e) {
                        setColor(COLOR_RED);
                        std::cerr << "[!] Error deleting " << entry.path().string() << ": " << e.what() << std::endl;
                        setColor(COLOR_WHITE);
                    }
                }
            }
        }
    }

    std::system("cls");
    setColor(COLOR_GREEN);
    std::cout << "[+] All logs and caches have been cleaned. Enjoy your game!" << std::endl;
    setColor(COLOR_WHITE);
}

int main()
{
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
    std::cout << "This tool will delete logs and cache files related to Riot Games." << std::endl << std::endl;

    char choice;
    std::cout << "Do you want to clean logs from all drives? (Y/N): ";
    std::cin >> choice;
    choice = std::toupper(choice);

    if (choice == 'Y') {
        cleanLogs();
        system("PAUSE");
    }
    else if (choice == 'N') {
        char driveLetter;
        std::cout << "Enter the drive letter where League is installed (A-Z): ";
        std::cin >> driveLetter;
        driveLetter = std::toupper(driveLetter);

        if (std::isalpha(driveLetter)) {
            stopProcesses();
            std::system("cls");

            setColor(COLOR_YELLOW);
            std::cout << "[-] Deleting all Riot/League logs and caches from drive " << driveLetter << ":" << std::endl;
            setColor(COLOR_WHITE);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            std::string drive(1, driveLetter);
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

            std::string prefetchPath = drive + ":\\Windows\\Prefetch";
            if (std::filesystem::exists(prefetchPath)) {
                setColor(COLOR_YELLOW);
                std::cout << "[-] Deleting Prefetch files in " << prefetchPath << std::endl;
                setColor(COLOR_WHITE);
                for (const auto& entry : std::filesystem::directory_iterator(prefetchPath)) {
                    std::string filename = entry.path().filename().string();
                    if (filename.find("LEAGUE") != std::string::npos || filename.find("RIOT") != std::string::npos) {
                        try {
                            std::filesystem::remove(entry.path());
                            setColor(COLOR_CYAN);
                            std::cout << "[-] Deleted: " << entry.path().string() << std::endl;
                            setColor(COLOR_WHITE);
                        }
                        catch (const std::filesystem::filesystem_error& e) {
                            setColor(COLOR_RED);
                            std::cerr << "[!] Error deleting " << entry.path().string() << ": " << e.what() << std::endl;
                            setColor(COLOR_WHITE);
                        }
                    }
                }
            }

            std::system("cls");
            setColor(COLOR_GREEN);
            std::cout << "[+] All logs and caches have been cleaned from drive " << driveLetter << ":. Enjoy your game!" << std::endl;
            setColor(COLOR_WHITE);
            system("PAUSE");
        }
        else {
            setColor(COLOR_RED);
            std::cout << "[!] Invalid drive letter. Please enter a letter (A-Z)." << std::endl;
            setColor(COLOR_WHITE);
            system("PAUSE");
        }
    }
    else {
        setColor(COLOR_RED);
        std::cout << "[!] Invalid option. Exiting..." << std::endl;
        setColor(COLOR_WHITE);
        system("PAUSE");
    }

    return 0;
}