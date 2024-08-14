#include "wifimanager.h"
#include <iostream>
#include "savedwifi.h"

WiFiManager::WiFiManager(){}

WiFiManager::~WiFiManager(){
    for (WiFi* wifi : m_wifiNetworks) {
        delete wifi;
    }
}

void WiFiManager::enableWiFi(){
    std::string  wifiEnableCommand = "nmcli radio wifi on";
    int result = system(wifiEnableCommand.c_str());

    if (result == 0) {
        std::cout << "WiFi has been enabled successfully." << std::endl;
    } else {
        std::cerr << "Failed to enable WiFi. Exit code: " << result << std::endl;
    }
}

void WiFiManager::disableWiFi(){
    std::string wifiDisableCommand = "nmcli radio wifi off";
    int result = system(wifiDisableCommand.c_str());

    if (result == 0) {
        std::cout << "WiFi has been disabled successfully." << std::endl;
    } else {
        std::cerr << "Failed to disable WiFi. Exit code: " << result << std::endl;
    }
}

void WiFiManager::retrieveWiFiNetworks(){
    m_wifiNetworks = m_wifiLoader.loadWiFiNetworks();

}

void WiFiManager::displayWiFiNetworks() const {


    const size_t serialWidth = 5;
    const size_t ssidWidth = 30;
    const size_t signalStrengthWidth = 20;
    const size_t securityWidth = 15;
    const size_t statusWidth = 15;

    std::cout << "\nAvailable WiFi Networks:\n";
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << formatColumn("No.", serialWidth)
              << formatColumn("SSID", ssidWidth)
              << formatColumn("Signal-Strength", signalStrengthWidth)
              << formatColumn("Security", securityWidth)
              << formatColumn("Status", statusWidth)
              << "\n--------------------------------------------------------------------------------\n";

    for (size_t index = 0; index < m_wifiNetworks.size(); ++index) {

        const WiFi* network = m_wifiNetworks[index];
        std::cout << formatColumn(std::to_string(index + 1), serialWidth)
                  << formatColumn(network->getSSID(), ssidWidth)
                  << formatColumn(network->getSignalStrength(), signalStrengthWidth)
                  << formatColumn(network->getSecurity(), securityWidth)
                  << formatColumn(network->getStatus(), statusWidth)
                  << '\n';
    }
}

void WiFiManager::connectToWiFi(size_t index) {

    if (index < 1 || index > m_wifiNetworks.size()) {
        std::cerr << "Invalid choice. Please enter a valid number." << std::endl;
        return;
    }

    WiFi* selectedNetwork = m_wifiNetworks[index - 1];

    if (selectedNetwork->getStatus() == "Connected") {
        std::cout << "You are already connected to " << selectedNetwork->getSSID() << std::endl;
        return;
    }

    if (selectedNetwork->getStatus() == "Saved") {
        std::string wifiConnectionCommand = "sudo nmcli dev wifi connect '" + selectedNetwork->getSSID() + "' password '" + selectedNetwork->getPassword() + "'";
        int result = std::system(wifiConnectionCommand.c_str());

        if (result == 0) {
            std::cout << "Successfully connected to " << selectedNetwork->getSSID() << std::endl;
            selectedNetwork->setStatus("Connected");
        } else {
            std::cerr << "Failed to connect to " << selectedNetwork->getSSID() << std::endl;
        }
        return;
    }

    std::cout << "Enter the password for " << selectedNetwork->getSSID() << ": ";
    std::string password;
    std::getline(std::cin, password);
    selectedNetwork->setPassword(password);

    std::string wifiConnectionCommand = "sudo nmcli dev wifi connect '" + selectedNetwork->getSSID() + "' password '" + selectedNetwork->getPassword() + "'";
    int result = std::system(wifiConnectionCommand.c_str());


    if (result == 0) {
        std::cout << "Successfully connected to " << selectedNetwork->getSSID() << std::endl;
        selectedNetwork->setStatus("Connected");
        savedwifi.saveWiFi(*selectedNetwork);
    } else {
        std::cerr << "Failed to connect to " << selectedNetwork->getSSID() << std::endl;
        selectedNetwork->setPassword("");
    }
}

void WiFiManager::sortWiFiNetworks()
{
    for (size_t firstIndex = 0; firstIndex < m_wifiNetworks.size() - 1; ++firstIndex) {
        for (size_t secondIndex = 0; secondIndex < m_wifiNetworks.size() - firstIndex - 1; ++secondIndex) {
            bool swap = false;
            if (m_wifiNetworks[secondIndex]->getStatus() == "Available" && m_wifiNetworks[secondIndex + 1]->getStatus() == "Connected") {
                swap = true;
            } else if (m_wifiNetworks[secondIndex]->getStatus() == "Saved" && m_wifiNetworks[secondIndex + 1]->getStatus() == "Connected") {
                swap = true;
            } else if (m_wifiNetworks[secondIndex]->getStatus() == "Available" && m_wifiNetworks[secondIndex + 1]->getStatus() == "Saved") {
                swap = true;
            }
            if (swap) {
                std::swap(m_wifiNetworks[secondIndex], m_wifiNetworks[secondIndex + 1]);
            }
        }
    }
}

size_t WiFiManager::getNumberOfNetworks() const {
    return m_wifiNetworks.size();
}

std::string WiFiManager::formatColumn(const std::string& str, size_t width) const {
    if (str.length() > width) {
        return str.substr(0, width - 3) + "...";
    }
    return str + std::string(width - str.length(), ' ');
}
