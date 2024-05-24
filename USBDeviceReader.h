#ifndef USBDEVICEREADER_H
#define USBDEVICEREADER_H

#include <fstream>
#include <string>
#include <stdexcept>

class USBDeviceReader {
public:
	void readAndPrintData(const std::string& filename);
};

#endif // USBDEVICEREADER_H