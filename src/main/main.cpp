//
//  main.cpp

#include <fstream>
#include <iostream>

#include "src/lib/jsonparser.hpp"
#include "src/lib/rectangle.hpp"
#include "src/lib/rectangleoperations.hpp"

using json = nlohmann::json;

int main(int argc, const char *argv[]) {
    
    std::string ifilename;
    
    // Read the input file from the console and exit if no input file is
    // provided
    if (argc > 1) {
        ifilename = argv[1];
    } else {
        std::cout << "Missing input Json. Please kindly enter the complete path of "
        "your Json file.";
        exit(1);
    }
    
    // Instantiate Json parser to parse input json and return a vector of input
    // Rectangles
    auto parser = JsonParser<Rectangle>(ifilename);
    std::vector<Rectangle> readRectangles;
    
    try {
        readRectangles = parser.readRectangleData();
    } catch (const std::string &error) {
        std::cout << error << std::endl;
        exit(1);
    }
    
    // Call to the print function to print the input rectangles
    MessageType messageType = MessageType::Original;
    std::cout << "Input data" << std::endl;
    printRectangles(readRectangles, messageType);
    
    // Call to the intersectons computing function which returns a vector of
    // intersections
    auto intersections = performIntersections(readRectangles);
    std::cout << std::endl;
    
    // Call to the print function to print the intersections
    messageType = MessageType::Intersections;
    std::cout << "Evaluated Intersections" << std::endl;
    printRectangles(intersections, messageType);
    
    return 0;
}
