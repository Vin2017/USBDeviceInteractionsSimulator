#include "USBDeviceReader.h"

int main() {
    USBDeviceReader usbDeviceReader;
    const std::string filename = "data.txt";
    usbDeviceReader.readAndPrintData(filename);
    return 0;
}