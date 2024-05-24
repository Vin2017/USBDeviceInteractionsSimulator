#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include "gtest/gtest.h" // Include Google Test header
#include "USBDeviceReader.h"

// Helper function to create a test data file
void createTestDataFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file(filename);
    ASSERT_TRUE(file.is_open());
    for (int value : data) {
        file << value << std::endl;
    }
    file.close();
}

TEST(DataCollectorTest, ReadsAndPrintsValidData) {
    const std::string testFilename = "test_data.txt";
    const std::vector<int> testData = { 10, 20, 30, 40 };

    // Create a temporary test data file before the test
    createTestDataFile(testFilename, testData);

    USBDeviceReader usbDeviceReader;

    testing::internal::CaptureStdout(); // Capture standard output for testing

    // Start reading data in a separate thread(simulate main function)
    std::thread readerThread([&usbDeviceReader, testFilename]() {
        usbDeviceReader.readAndPrintData(testFilename);
        });


    // Allow some time for the reader to process the file
    std::this_thread::sleep_for(std::chrono::seconds(10));

    // Stop the thread
    readerThread.detach(); // Or implement a proper shutdown mechanism
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << "The value of myVariable is: " << output << std::endl;
    // Remove the temporary test data file after the test
    remove(testFilename.c_str()); // Use C-style for compatibility

    // Test expected output format for each data point
    for (int dataPoint : testData) {
        EXPECT_NE(output.find("Read data: " + std::to_string(dataPoint)), std::string::npos);
    }
}

// Test case for DataCollector class to handle invalid data gracefully
TEST(DataCollectorTest, HandlesInvalidDataGracefully) {
    const std::string testFilename = "test_data_invalid.txt";
    const std::string invalidData = "invalid_data";

    // Create a temporary test data file with invalid data before the test
    std::ofstream file(testFilename);
    ASSERT_TRUE(file.is_open());
    file << "10" << std::endl; // Write a valid data point first
    file << invalidData << std::endl;
    file.close();

    USBDeviceReader usbDeviceReader;
    testing::internal::CaptureStderr(); // Capture standard error for testing
    // Start reading data in a separate thread(simulate main function)
    std::thread readerThread([&usbDeviceReader, testFilename]() {
        usbDeviceReader.readAndPrintData(testFilename);
        });


    // Allow some time for the reader to process the file
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Stop the thread
    readerThread.detach(); // Or implement a proper shutdown mechanism

    std::string errorOutput = testing::internal::GetCapturedStderr();

    std::cout << "The value of myVariable is: " << errorOutput << std::endl;
    // Remove the temporary test data file after the test
    remove(testFilename.c_str()); // Use C-style for compatibility

    // Test expected error message for invalid data
    EXPECT_NE(errorOutput.find("Invalid data encountered: " + invalidData), std::string::npos);
}






