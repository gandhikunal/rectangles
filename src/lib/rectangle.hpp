//
//  rectangle.hpp

#ifndef rectangle_hpp
#define rectangle_hpp

#include <iostream>
#include <sstream>
#include <string>

// Enum used to indicate the context in which the Rectangle needs to be
// displayed
enum class MessageType { Original, Intersections };

struct Rectangle {
    
    std::string name = "";
    int xCoordinate = 0;
    int yCoordinate = 0;
    int height = 0;
    int width = 0;
    
    Rectangle();
    
    Rectangle(std::string newName, int newxCord, int newyCord, unsigned newHeight,
              unsigned newWidth);
    
    bool operator==(const Rectangle &rhs) const;
    
    void displayRectangle(const Rectangle &r, MessageType messageType) const;
};

#endif /* rectangle_hpp */
