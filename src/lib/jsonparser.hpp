//
//  jsonparser.hpp

#ifndef jsonparser_hpp
#define jsonparser_hpp

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "json.hpp"
#include "rectangle.hpp"

using json = nlohmann::json;

template <class T> class JsonParser {
public:
    JsonParser(std::string filename) : filename(filename), rectangleList() {}
    
    // Function to parse and read data returned by the parsing library
    inline std::vector<T> readRectangleData() {
        std::ifstream ifile(filename);
        if (!ifile) {
            std::cerr << "Couldn't open the file!, Make sure you entered the "
            "complete path of the file."
            << std::endl;
            exit(1);
        }
        // Holds top most level nodes in the json
        json topContainer;
        
        try {
            ifile >> topContainer;
        } catch (json::parse_error &error) {
            const std::string errMsg = "Invalid Json file provided.";
            throw errMsg;
        }
        
        try {
            // Reading in the value from key rects which holds the Rectangles
            json inputRectangles = topContainer.at("rects");
            
            int counter = 1;
            
            for (auto it : inputRectangles) {
                // Ensuring only the first ten Rectangles are populated in
                // case there would be more
                if (counter > 10) {
                    break;
                }
                json rect = it;
                
                // String stream declaration to create the name of the
                // Rectangle from an int value
                std::stringstream rectName;
                rectName << counter;
                try {
                    // Reading the Rectangles properties from the Json
                    auto x = rect.at("x");
                    auto y = rect.at("y");
                    auto w = rect.at("w");
                    auto h = rect.at("h");
                    
                    // Check to ensure data type matches our
                    // expectations for input data
                    if (x.is_number() && y.is_number() && w.is_number() &&
                        h.is_number()) {
                        
                        // Check to ensure we have a valid Rectanlge with positive width and
                        // height
                        if ((rect["w"] > 0) && (rect["h"] > 0)) {
                            Rectangle rectangle = Rectangle(rectName.str(), x, y, h, w);
                            rectangleList.push_back(rectangle);
                        } else {
                            std::string errMsg = "Negative Values provided in the Json file.";
                            throw errMsg;
                        }
                    } else {
                        std::string errMsg = "Invalid values presented in the Json file.";
                        throw errMsg;
                    }
                    ++counter;
                } catch (json::exception &error) {
                    const std::string errMsg = "Invalid keys presented in the Json file.";
                    throw errMsg;
                }
            }
        } catch (json::exception &error) {
            const std::string errMsg = "No rects key found in the Json file.";
            throw errMsg;
        }
        // Return a list of read input Rectangles
        return rectangleList;
    }
    
private:
    std::string filename;
    std::vector<T> rectangleList;
};

#endif /* jsonparser_hpp */
