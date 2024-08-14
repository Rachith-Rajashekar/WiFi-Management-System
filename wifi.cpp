#include "wifi.h"
#include <iostream>

WiFi::WiFi(const std::string& ssid, const std::string& signalStrength,
           const std::string& security, const std::string& status)
    : m_wifiSSID(ssid), m_wifiSignalStrength(signalStrength),
    m_wifiSecurity(security), m_wifiStatus(status) {}

WiFi::~WiFi() {}

std::string WiFi::getSSID() const{
    return m_wifiSSID;
}
std::string WiFi::getSignalStrength() const {
    return m_wifiSignalStrength;
}
std::string WiFi::getSecurity() const {
    return m_wifiSecurity;
}
std::string WiFi::getStatus() const {
    return m_wifiStatus;
}
std::string WiFi::getPassword() const {
    return m_wifiPassword;
}

void WiFi::setSSID(const std::string& ssid) {
    m_wifiSSID = ssid;
}
void WiFi::setSignalStrength(const std::string& signalStrength) {
    m_wifiSignalStrength = signalStrength;
}
void WiFi::setSecurity(const std::string& security) {
    m_wifiSecurity = security;
}
void WiFi::setStatus(const std::string& status) {
    m_wifiStatus = status;
}
void WiFi::setPassword(const std::string& password) {
    m_wifiPassword = password;
}
