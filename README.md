# USB Device Interactions Simulator

This console application simulates interactions with a USB device by reading data from a text file.

## Overview

The application consists of the following files:

1. **Main file**: `USBDeviceInteractionsSimulator.cpp`
   - Entry point of the application.
   - Instantiates a `USBDeviceReader` object and reads data from a specified file.

2. **Header file**: `USBDeviceReader.h`
   - Declaration of the `USBDeviceReader` class.

3. **Source file**: `USBDeviceReader.cpp`
   - Definition of the `USBDeviceReader` class methods.
   - Implements reading and printing data from a file.

4. **Python script**: `data_generator.py`
   - Generates random data and appends it to a text file at regular intervals.

5. **Data file**: `data.txt`
   - Text file containing generated data. Updated by the Python script.

6. **Test file**: `USBDeviceReaderTests.cpp`
   - Contains Google Test cases for testing the `USBDeviceReader` class.

## Usage

To simulate the USB device interactions:

1. Run the Python script `data_generator.py` in the root folder.
```
	python data_generator.py
```
This script generates random data and appends it to `data.txt` every 2 seconds.

2. Compile and run the C++ application `USBDeviceInteractionsSimulator`.
 ```
 g++ USBDeviceInteractionsSimulator.cpp USBDeviceReader.cpp -o USBDeviceInteractionsSimulator
./USBDeviceInteractionsSimulator
```

This application reads data from `data.txt` every 2 seconds and prints it to the console.

## Testing

Unit tests for the `USBDeviceReader` class are provided in `USBDeviceReaderTests.cpp`.
To run the tests, compile and execute the test file using Google Test framework.
