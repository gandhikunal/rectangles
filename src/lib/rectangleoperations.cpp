//
//  rectangleoperations.cpp

#include "rectangleoperations.hpp"

void printRectangles(const std::vector<Rectangle> &v, MessageType messageType) {
    // Switch on message type to display appropriate message header
    switch (messageType) {
        case MessageType::Intersections: {
            if (v.size() == 0) {
                std::cout << "There are no intersections to display." << std::endl;
                return;
            }
            break;
        }
        case MessageType::Original: {
            if (v.size() == 0) {
                std::cout << "There are no rectangles to display." << std::endl;
                return;
            }
            break;
        }
    }
    // Call the display method on the Rectangle to print itself
    for (auto i : v) {
        i.displayRectangle(i, messageType);
    }
}

// Compare two Rectangles to check if they intersect, returning an intersecting
// Rectangle if they do or an optional null ptr if they dont
static std::optional<Rectangle> compareRectangles(const Rectangle &r1,
                                                  const Rectangle &r2) {
    
    // Calculating the bottom corner coordinates for the first Rectangle
    int r1BottomRightCornerX = r1.xCoordinate + r1.height;
    int r1BottomRightCornerY = r1.yCoordinate + r1.width;
    // Calculating the bottom corner coordinates for the second Rectangle
    int r2BottomRightCornerX = r2.xCoordinate + r2.height;
    int r2BottomRightCornerY = r2.yCoordinate + r2.width;
    
    Rectangle intersection;
    
    // Condition to check if the Rectangles do not intersect
    if (((r1BottomRightCornerX <= r2.xCoordinate) &&
         (r1BottomRightCornerY <= r2.yCoordinate)) ||
        ((r1.xCoordinate >= r2BottomRightCornerX) &&
         (r1.yCoordinate >= r2BottomRightCornerY))) {
            return std::nullopt;
        } else {
            int newX;
            int newY;
            int newWidth;
            int newHeight;
            newX = std::max(r1.xCoordinate, r2.xCoordinate);
            newY = std::max(r1.yCoordinate, r2.yCoordinate);
            newHeight = std::min(r1BottomRightCornerX, r2BottomRightCornerX) - newX;
            newWidth = std::min(r1BottomRightCornerY, r2BottomRightCornerY) - newY;
            // If Rectangles align or touch each other along the X
            // or Y axis, the resulting area between them will be negative or zero
            // reflected by the width or height, which is not an intersection
            if ((newWidth <= 0) || (newHeight <= 0)) {
                return std::nullopt;
            }
            intersection =
            Rectangle(r1.name + ", " + r2.name, newX, newY, newHeight, newWidth);
        }
    
    return intersection;
}

// Debug function written to debug the recursion tree
// static void debugRecursion(int number, std::string msg) {
//    std::stringstream numberTabs;
//
//    for (auto i = 1; i <= number; ++i) {
//        numberTabs << "\t";
//    }
//    std::cout << numberTabs.str() << msg << std::endl;
//}

// Recurse over the range of Rectangles provided to find if they intersect with
// the first Rectangle parameter
static void intersectionsRecursive(const Rectangle &firstRectangle,
                                   std::vector<Rectangle>::const_iterator begin,
                                   std::vector<Rectangle>::const_iterator end,
                                   std::vector<Rectangle> &intersections) {
    // Exit condition for the recursion when there is only one Rectangle left
    // in the range
    if ((end - begin) < 1) {
        return;
    }
    for (std::vector<Rectangle>::const_iterator j = begin; j != end; ++j) {
        // If the there is an intersection between two Rectangles, we
        // recurse over the remaining range with this intersection as the
        // first Rectangle parameter to find all possible intersections with this
        // intersection found
        if (auto result = compareRectangles(firstRectangle, *j)) {
            intersections.push_back(*result);
            intersectionsRecursive(*result, j + 1, end, intersections);
        }
    }
}

// Wrapper function which iterates over the input Rectangles one at a time and
// finds all possible intersections involving that Rectangle and the remaining
// Rectangles in the input range
std::vector<Rectangle>
performIntersections(std::vector<Rectangle> &originalRectangles) {
    std::vector<Rectangle> intersections;
    // Check to ensure you have more than one Rectangle to evaluate an
    // intersection
    if (originalRectangles.size() >= 2) {
        for (std::vector<Rectangle>::const_iterator i = originalRectangles.begin();
             i != (originalRectangles.end() - 1); ++i) {
            intersectionsRecursive(*i, i + 1, originalRectangles.end(),
                                   intersections);
        }
    }
    return intersections;
}
