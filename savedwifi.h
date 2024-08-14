#ifndef SAVEDWIFI_H
#define SAVEDWIFI_H

#include "wifi.h"
#include <vector>
#include <string>

class SavedWiFi {
private:
    std::vector<WiFi*> m_savedWiFiList;
    const std::string m_fileName = "saved_wifi.txt";
    WiFi savedNetwork;

public:
    SavedWiFi();
    ~SavedWiFi();
    void loadSavedWiFi();
    void saveWiFi(const WiFi& wifi);
    std::string findSavedWiFi(WiFi &wifi);
};

#endif
