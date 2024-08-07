#include "wifi.h"


WiFi::WiFi(){}

WiFi::WiFi(int wifiNumber, int wifiSignalStrength, const std::string& wifiName, const std::string& wifiPassword, const std::string& wifiStatus):
    m_wifiNumber(wifiNumber),
    m_wifiSignalStrength(wifiSignalStrength),
    m_wifiName(wifiName),
    m_wifiPassword(wifiPassword),
    m_wifiStatus(wifiStatus) {}

WiFi::~WiFi() {}

int WiFi::getWiFiNumber() const
{
    return m_wifiNumber;
}

std::string WiFi::getWiFiName() const {
    return m_wifiName;
}

std::string WiFi::getWiFiPassword() const {
    return m_wifiPassword;
}

int WiFi::getWiFiSignalStrength() const {
    return m_wifiSignalStrength;
}

std::string WiFi::getWiFiStatus() const {
    return m_wifiStatus;
}

void WiFi::setWiFiNumber(const int wifiNumber){
    this->m_wifiNumber = wifiNumber;
}

void WiFi::setWiFiName(const std::string &wifiName)
{
    this->m_wifiName = wifiName;
}

void WiFi::setWiFiSignalStrength(const int wifiSignalStrength)
{
    this->m_wifiSignalStrength = wifiSignalStrength;
}

void WiFi::setWiFiPassword(const std::string& wifiPassword) {
    this->m_wifiPassword = wifiPassword;
}

void WiFi::setWiFiStatus(const std::string& wifiStatus) {
    this->m_wifiStatus = wifiStatus;
}
