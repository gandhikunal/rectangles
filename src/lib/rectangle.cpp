//
//  rectangle.cpp

#include "rectangle.hpp"

// Constructors
Rectangle::Rectangle() {}

Rectangle::Rectangle(std::string newName, int newxCord, int newyCord,
                     unsigned newHeight, unsigned newWidth)
: name(newName), xCoordinate(newxCord), yCoordinate(newyCord),
height(newHeight), width(newWidth) {}

// Method to display a Rectangles information, using the class MessageType wihch
// dictates the context in which the Rectangle is displayed
void Rectangle::displayRectangle(const Rectangle &r,
                                 MessageType messageType) const {
    std::stringstream intersectMsgDisplay;
    std::stringstream originalMsgDisplay;
    std::stringstream commonMessage;
    commonMessage << " is at (x: " << r.xCoordinate << ", y: " << r.yCoordinate
    << ")"
    << ", "
    << "(w = " << r.width << ", h = " << r.height << ")";
    switch (messageType) {
        case MessageType::Intersections: {
            std::size_t lastComma = r.name.find_last_of(",");
            intersectMsgDisplay << "Intersection of rectangles "
            << r.name.substr(0, lastComma) + " and " +
            r.name.substr(lastComma + 1);
            std::cout << intersectMsgDisplay.str() << commonMessage.str() << std::endl;
            break;
        }
        case MessageType::Original: {
            originalMsgDisplay << "Rectangles " << r.name;
            std::cout << originalMsgDisplay.str() << commonMessage.str() << std::endl;
            break;
        }
    }
}

// Overloading of the == operator to make Rectangles equatable
bool Rectangle::operator==(const Rectangle &rhs) const {
    return std::tie(this->name, this->xCoordinate, this->yCoordinate,
                    this->height, this->width) ==
    std::tie(rhs.name, rhs.xCoordinate, rhs.yCoordinate, rhs.height,
             rhs.width);
}
