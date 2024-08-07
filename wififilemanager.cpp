#include "wififilemanager.h"



WiFiFileManager::WiFiFileManager(){}

WiFiFileManager::~WiFiFileManager() {
    std::cout << "WiFiFileManager Destructor Called" << std::endl;
}

void WiFiFileManager::readFromCSV(const std::string &filename, WiFiManager &wifiManager)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {

        std::stringstream ss(line);
        std::string name, password, status;
        int number,signalStrength;
        ss >> number;
        ss.ignore();
        std::getline(ss, name, ',');
        std::getline(ss, password, ',');
        ss >> signalStrength;
        ss.ignore();
        std::getline(ss, status);
        wifiManager.loadWiFiDetails(WiFi(number,signalStrength,name,password,status));
    }
    file.close();
}


