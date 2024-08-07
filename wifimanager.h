#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <vector>
#include "wifi.h"


class WiFiManager {
private:
    std::vector<WiFi> m_wifiList;
    WiFi* findWiFiByNumber(const int number);
public:
    WiFiManager();
    ~WiFiManager();

    void loadWiFiDetails(const WiFi &wifi);
    void displayWiFiList() const;
    void sortWiFiList();
    void connectToWiFi();
};

#endif

