#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <vector>
#include "wifi.h"
#include "wifiloader.h"
#include "savedwifi.h"

class WiFiManager {
public:
    WiFiManager();
    ~WiFiManager();
    void enableWiFi();
    void disableWiFi();
    void retrieveWiFiNetworks();
    void displayWiFiNetworks() const;
    void connectToWiFi(size_t index);
    void sortWiFiNetworks();
    size_t getNumberOfNetworks() const;

private:
    std::vector<WiFi*> m_wifiNetworks;
    WiFiLoader m_wifiLoader;
    SavedWiFi savedwifi;


    std::string formatColumn(const std::string& str, size_t width) const;
};

#endif
