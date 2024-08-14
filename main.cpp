#include <iostream>
#include "wifimanager.h"

int main() {
    WiFiManager wifiManager;
    int onOffChoice;
    int choice = 0;
     std::cout << "WiFi Management System" << std::endl;

    do {
        std::cout << "Connection Menu" << std:: endl;
        std::cout << "1. Enable WiFi" << std::endl;
        std::cout << "2. Disable WiFi" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> onOffChoice;
        std::cin.ignore();
        switch(onOffChoice) {

        case 1 :

                wifiManager.enableWiFi();

                do {

                    wifiManager.retrieveWiFiNetworks();
                    wifiManager.sortWiFiNetworks();
                    wifiManager.displayWiFiNetworks();

                    std::cout << "\nMenu:\n";
                    std::cout << "1. Connect to WiFi\n";
                    std::cout << "2. Exit\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> choice;
                    std::cin.ignore();

                    switch (choice) {
                    case 1: {
                        size_t selectedIndex;
                        std::cout << "Enter the serial number of the WiFi network you want to connect to: ";
                        std::cin >> selectedIndex;
                        std::cin.ignore();

                        if (selectedIndex < 1 || selectedIndex > wifiManager.getNumberOfNetworks()) {
                            std::cerr << "Invalid choice. Please enter a between 1 and " << wifiManager.getNumberOfNetworks() << "." << std::endl;
                        } else {
                            wifiManager.connectToWiFi(selectedIndex);
                        }
                        break;
                    }
                    case 2:
                        std::cout << "Exiting Menu" << std::endl;
                        break;
                    default:
                        std::cerr << "Invalid choice. Please enter 1 or 2." << std::endl;
                        break;
                    }
                } while (choice < 2);
                break;

        case 2 :
            wifiManager.disableWiFi();
            break;
        case 3:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cerr << "Invalid choice. Please enter 1 or 2." << std::endl;
            break;
        }
    }while(onOffChoice!=3);
    return 0;
}
