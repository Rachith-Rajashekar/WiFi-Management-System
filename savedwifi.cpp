#include "savedwifi.h"
#include <fstream>
#include <sstream>
#include <iostream>

SavedWiFi::SavedWiFi(){}

SavedWiFi::~SavedWiFi() {
    for (WiFi* wifi : m_savedWiFiList) {
        delete wifi;
    }
}

void SavedWiFi::loadSavedWiFi() {
    std::ifstream file(m_fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open " << m_fileName << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {

        std::stringstream stream(line);
        std::string token;

        WiFi* savedNetwork = new WiFi;

        std::getline(stream, token, ':');

        savedNetwork->setStatus(token);

        std::getline(stream, token, ':');

        savedNetwork->setSSID(token);

        std::getline(stream, token, ':');
        savedNetwork->setSignalStrength(token);

        std::getline(stream, token, ':');
        savedNetwork->setSecurity(token);

        std::getline(stream, token);
        savedNetwork->setPassword(token);

        m_savedWiFiList.push_back(savedNetwork);

    }
    file.close();

}

void SavedWiFi::saveWiFi(const WiFi& wifi) {
    std::ofstream file(m_fileName, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << m_fileName << " for appending." << std::endl;
        return;
    }

    file << wifi.getStatus() << ':'
         << wifi.getSSID() << ':'
         << wifi.getSignalStrength() << ':'
         << wifi.getSecurity() << ':'
         << wifi.getPassword() << '\n';
    file.close();
}

std::string SavedWiFi::findSavedWiFi(WiFi& wifi) {
    for (const WiFi* saved : m_savedWiFiList) {
        if((saved->getSSID() == wifi.getSSID())){
            return saved->getPassword();
        }

    }return "";
}
