#ifndef WIFILOADER_H
#define WIFILOADER_H

#include <vector>
#include "wifi.h"
#include "savedwifi.h"

class WiFiLoader {
public:
    WiFiLoader();
    ~WiFiLoader();
    std::vector<WiFi *> loadWiFiNetworks();
private:
    SavedWiFi savedwifi;
};

#endif
