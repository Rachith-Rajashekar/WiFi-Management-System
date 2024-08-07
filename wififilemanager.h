#ifndef WIFIFILEMANAGER_H
#define WIFIFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "wifimanager.h"
#include "wifi.h"

class WiFiFileManager
{
    WiFiManager wifiManager;
public:
     WiFiFileManager();
     ~WiFiFileManager();

     void readFromCSV(const std::string& filename,WiFiManager &wifiManager);
};

#endif
