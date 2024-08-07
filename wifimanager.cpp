#include <iostream>
#include <vector>
#include "wifimanager.h"
#include "wifi.h"
#include "wififilemanager.h"

WiFiManager::WiFiManager() {}

WiFiManager::~WiFiManager()
{
    std::cout << "WiFiManager Destructor Called" << std::endl;
}

void WiFiManager::loadWiFiDetails(const WiFi &wifi)
{
    m_wifiList.push_back(wifi);
}

void WiFiManager::displayWiFiList() const {
    for (const WiFi& wifi : m_wifiList) {
        std::cout << "WiFi Number: " << wifi.getWiFiNumber()
                  << " | WiFi Name: " << wifi.getWiFiName()
                  << " | Signal Strength: " << wifi.getWiFiSignalStrength()
                  << " | Status: " << wifi.getWiFiStatus() << std::endl;
    }
}

void WiFiManager::sortWiFiList()
{
    for (size_t firstIndex = 0; firstIndex < m_wifiList.size() - 1; ++firstIndex) {
        for (size_t secondIndex = 0; secondIndex < m_wifiList.size() - firstIndex - 1; ++secondIndex) {
            bool swap = false;
            if (m_wifiList[secondIndex].getWiFiStatus() == "available" && m_wifiList[secondIndex + 1].getWiFiStatus() == "connected") {
                swap = true;
            } else if (m_wifiList[secondIndex].getWiFiStatus() == "saved" && m_wifiList[secondIndex + 1].getWiFiStatus() == "connected") {
                swap = true;
            } else if (m_wifiList[secondIndex].getWiFiStatus() == "available" && m_wifiList[secondIndex + 1].getWiFiStatus() == "saved") {
                swap = true;
            } else if (m_wifiList[secondIndex].getWiFiStatus() == m_wifiList[secondIndex + 1].getWiFiStatus()) {
                swap = m_wifiList[secondIndex].getWiFiSignalStrength() < m_wifiList[secondIndex + 1].getWiFiSignalStrength();
            }

            if (swap) {
                std::swap(m_wifiList[secondIndex], m_wifiList[secondIndex + 1]);
            }

            if (m_wifiList[secondIndex].getWiFiNumber() > m_wifiList[secondIndex + 1].getWiFiNumber()){
                int temperoryNumber = m_wifiList[secondIndex].getWiFiNumber();
                m_wifiList[secondIndex].setWiFiNumber(m_wifiList[secondIndex + 1].getWiFiNumber());
                m_wifiList[secondIndex + 1].setWiFiNumber(temperoryNumber) ;
            }
        }
    }
}


WiFi* WiFiManager::findWiFiByNumber(const int number)
{

    for (WiFi& wifi : m_wifiList) {
        if (wifi.getWiFiNumber() == number) {
            return &wifi;
        }
    } return nullptr;
}


void WiFiManager::connectToWiFi()
{
    int userInput;
    std::cout << "Enter Wifi Number : ";
    std::cin >> userInput;
    WiFi* wifiToConnect = findWiFiByNumber(userInput);

    if (wifiToConnect)
    {
        if (wifiToConnect->getWiFiStatus() == "available") {
            std::string password;

            std::cout << "Enter password for " << wifiToConnect->getWiFiName() << ": ";
            std::cin >> password;
            if(wifiToConnect->getWiFiPassword() == password){
                std::cout << "Connected" << std::endl;

            } else {
                std::cout << "Incorrect Password" << std::endl;
                return;
            }
        }

        for (WiFi& wifi : m_wifiList)
        {
            if (wifi.getWiFiStatus() == "connected")
            {
                wifi.setWiFiStatus("saved");
            }
        }
        wifiToConnect->setWiFiStatus("connected");
        sortWiFiList();
    } else {
        std::cout << "WiFi number not found." << std::endl;
    }
}

