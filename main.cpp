#include <iostream>
#include "wifimanager.h"
#include "wififilemanager.h"

int main() {

    WiFiManager wifiManager;
    WiFiFileManager wifiFileManager;
    wifiFileManager.readFromCSV("wifi_list.csv", wifiManager);

    int choice = 0;
    std::cout << "Wifi Management System" << std::endl;

    while(choice !=2){
        wifiManager.sortWiFiList();
        wifiManager.displayWiFiList();
        std::cout << "1. connect to wifi " << std::endl;
        std::cout << "2. exit " << std::endl;
        std::cin >> choice;

        switch(choice){
        case 1 :
             wifiManager.connectToWiFi();
            break;
        case 2 :
            return 0;
        default:
            std::cout << "Please Enter the valid option" << std::endl;
            break;
        }
    }
    return 0;
}
