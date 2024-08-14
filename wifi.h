#ifndef WIFI_H
#define WIFI_H

#include <string>

class WiFi {
public:
    WiFi(const std::string& ssid = "", const std::string& signalStrength = "",
         const std::string& security = "", const std::string& status = "");
    ~WiFi();

    std::string getSSID() const;
    std::string getSignalStrength() const;
    std::string getSecurity() const;
    std::string getStatus() const;
    std::string getPassword() const;

    void setSSID(const std::string& ssid);
    void setSignalStrength(const std::string& signalStrength);
    void setSecurity(const std::string& security);
    void setStatus(const std::string& status);
    void setPassword(const std::string& password);
private:
    std::string m_wifiSSID;
    std::string m_wifiSignalStrength;
    std::string m_wifiSecurity;
    std::string m_wifiStatus;
    std::string m_wifiPassword;
};

#endif
