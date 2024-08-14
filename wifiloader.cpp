#include "wifiloader.h"
#include "savedwifi.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

WiFiLoader::WiFiLoader(){}

WiFiLoader::~WiFiLoader(){}

std::vector<WiFi*> WiFiLoader::loadWiFiNetworks() {
    savedwifi.loadSavedWiFi();
    std::vector<WiFi*> networks;
    std::string wifiRetrievalCommand = "nmcli -t -f ACTIVE,SSID,SIGNAL,SECURITY dev wifi > wifi_list.txt";

    if (std::system(wifiRetrievalCommand.c_str()) != 0) {
        std::cerr << "Failed to execute nmcli command." << std::endl;
        return networks;
    }

    std::ifstream file("wifi_list.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open wifi_list.txt" << std::endl;
        return networks;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream stream(line);
        std::string token;
        std::string status;
        WiFi* network = new WiFi;

        std::getline(stream, status, ':');

        std::getline(stream, token, ':');
        network->setSSID(token);

        std::getline(stream, token, ':');
        network->setSignalStrength(token);

        std::getline(stream, token, ':');
        network->setSecurity(token);

        if(status== "yes"){
            network->setStatus("Connected");
        }else if((status == "no") && (savedwifi.findSavedWiFi(*network) != "")){
            network->setStatus("Saved");
            network->setPassword(savedwifi.findSavedWiFi(*network));
        }else{
            network->setStatus("Available");
        }

        networks.push_back(network);
    }

    file.close();
    std::remove("wifi_list.txt");

    return networks;
}
