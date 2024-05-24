#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include "USBDeviceReader.h"

void USBDeviceReader::readAndPrintData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (true) {
        while (std::getline(file, line)) {
            try {
                int data = std::stoi(line);
                std::cout << "Read data: " << data << std::endl;
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Invalid data encountered: " << line << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        file.clear(); // clear EOF flag
        file.seekg(0, std::ios::beg); // go back to the beginning of the file

    }
}

