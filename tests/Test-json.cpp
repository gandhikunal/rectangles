//
// Test-json.cpp

#include "gtest/gtest.h"

#include "src/lib/jsonparser.hpp"

// Test case to check if error message is thrown when an invalid json is provided
TEST(ProvidedInvalidJson, ThrowsWithACertainMessage) {
    std::string ifilename = "test-jsons/test-invalid-json.json";
    
    try {
        auto parser = JsonParser<Rectangle>(ifilename);
        auto readRectangles = parser.readRectangleData();
    } catch (const std::string &error) {
        EXPECT_EQ("Invalid Json file provided.", error);
    }
}

// Test case to check if error message is thrown when negative values are
// provided as width and height for the Rectangles
TEST(ProvidedJsonWithNegativeValuesForRectangle, ThrowsWithACertainMessage) {
    std::string ifilename = "test-jsons/test-negative-values.json";
    
    try {
        auto parser = JsonParser<Rectangle>(ifilename);
        auto readRectangles = parser.readRectangleData();
    } catch (const std::string &error) {
        EXPECT_EQ("Negative Values provided in the Json file.", error);
    }
}

// Test case to check if error message is thrown when the json does not contain
// the keys corresponding to Rectangles properties
TEST(ProvidedJsonWithoutRectangleInfoKeys, ThrowsWithACertainMessage) {
    std::string ifilename = "test-jsons/test-invalid-rectangle-keys.json";
    
    try {
        auto parser = JsonParser<Rectangle>(ifilename);
        auto readRectangles = parser.readRectangleData();
    } catch (const std::string &error) {
        EXPECT_EQ("Invalid keys presented in the Json file.", error);
    }
}

// Test case to check if error message is thrown when wrong data type is
// provided for the Rectangles properties
TEST(ProvidedJsonWithInvalidValueTpes, ThrowsWithACertainMessage) {
    std::string ifilename = "test-jsons/test-invalid-data-types.json";
    
    try {
        auto parser = JsonParser<Rectangle>(ifilename);
        auto readRectangles = parser.readRectangleData();
    } catch (const std::string &error) {
        EXPECT_EQ("Invalid values presented in the Json file.", error);
    }
}

// Test case to check if error message is thrown when the json does not contain
// the rects key
TEST(ProvidedJsonWithoutrectsKey, ThrowsWithACertainMessage) {
    std::string ifilename = "test-jsons/test-invalid-rects-key.json";
    
    try {
        auto parser = JsonParser<Rectangle>(ifilename);
        auto readRectangles = parser.readRectangleData();
    } catch (const std::string &error) {
        EXPECT_EQ("No rects key found in the Json file.", error);
    }
}

// Test case to check a valid vector of Rectangles is returned upon parsing a
// valid json
TEST(ProvideValidJsonWithRectangles, ReturnVectorOf4Rectangles) {
    std::string ifilename = "test-jsons/test-4rects.json";
    auto parser = JsonParser<Rectangle>(ifilename);
    auto readRectangles = parser.readRectangleData();
    std::vector<Rectangle> expectedReturnRectangles;
    Rectangle r1 = Rectangle("1", 100, 100, 80, 250);
    Rectangle r2 = Rectangle("2", 120, 200, 250, 250);
    Rectangle r3 = Rectangle("3", 140, 160, 100, 250);
    Rectangle r4 = Rectangle("4", 160, 140, 190, 350);
    expectedReturnRectangles.push_back(r1);
    expectedReturnRectangles.push_back(r2);
    expectedReturnRectangles.push_back(r3);
    expectedReturnRectangles.push_back(r4);
    EXPECT_EQ(expectedReturnRectangles, readRectangles);
}

// Test case to check that only first ten Rectangles are returned if the json
// contains more that ten Rectangles
TEST(ProvideValidJsonWithMoreThan10Rectangles,
     ReturnVectorOfFirst10Rectangles) {
    std::string ifilename = "test-jsons/test-morethan10.json";
    auto parser = JsonParser<Rectangle>(ifilename);
    auto readRectangles = parser.readRectangleData();
    EXPECT_EQ(10, readRectangles.size());
}
