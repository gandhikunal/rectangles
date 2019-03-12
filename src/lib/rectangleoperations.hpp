//
//  rectangleoperations.hpp

#ifndef rectangleoperations_hpp
#define rectangleoperations_hpp

#include <functional>
#include <iostream>
#include <optional>
#include <sstream>
#include <vector>

#include "rectangle.hpp"

void printRectangles(const std::vector<Rectangle> &v, MessageType messageType);

std::vector<Rectangle>
performIntersections(std::vector<Rectangle> &originalRectangles);

#endif /* rectangleoperations_hpp */
