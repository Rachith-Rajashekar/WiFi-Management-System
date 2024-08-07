#ifndef WiFi_H
#define WiFi_H
#include <iostream>
#include <string>

class WiFi {
private:
    int m_wifiNumber, m_wifiSignalStrength;
    std::string m_wifiName;
    std::string m_wifiStatus;
    std::string m_wifiPassword;
public:
    WiFi();
    WiFi(int wifiNumber, int wifiSignalStrength,const std::string& wifiName, const std::string& wifiPassword, const std::string& wifiStatus);
    ~WiFi();

    int getWiFiNumber() const;
    std::string getWiFiName() const;
    std::string getWiFiPassword() const;
    int getWiFiSignalStrength() const;
    std::string getWiFiStatus() const;

    void setWiFiNumber(const int wifiNumber);
    void setWiFiName( const std::string& wifiName);
    void setWiFiPassword(const std::string& wifiPassword);
    void setWiFiSignalStrength(const int wifiSignalStrength);
    void setWiFiStatus(const std::string& wifiStatus);
};

#endif
