//
// Test-rectangles.cpp

#include "gtest/gtest.h"

#include "src/lib/rectangleoperations.hpp"

// Test case to check that when only Rectangle given as input, the output of
// intersections is an empty vector
TEST(PerformIntersectionsWithOneRectangleShould,
     ReturnEmptyVectorOfIntersections) {
    std::vector<Rectangle> inputRectangles;
    std::vector<Rectangle> expectedReturnRectangles;
    Rectangle i1 = Rectangle("1, 2", 100, 200, 100, 100);
    inputRectangles.push_back(i1);
    auto testReturnIntersections = performIntersections(inputRectangles);
    EXPECT_EQ(expectedReturnRectangles, testReturnIntersections);
}

// Test case to validate the correctness of the program with an input of 5
// concentric Rectangles
TEST(PerformIntersectionsWith5ConcentricRectanglesShould,
     ReturnVectorOf26Intersections) {
    std::vector<Rectangle> inputRectangles;
    std::vector<Rectangle> expectedReturnRectangles;
    Rectangle i1 = Rectangle("1", 600, 600, 100, 100);
    Rectangle i2 = Rectangle("2", 500, 500, 400, 400);
    Rectangle i3 = Rectangle("3", 400, 400, 600, 600);
    Rectangle i4 = Rectangle("4", 300, 300, 800, 800);
    Rectangle i5 = Rectangle("5", 200, 200, 1000, 1000);
    inputRectangles.push_back(i1);
    inputRectangles.push_back(i2);
    inputRectangles.push_back(i3);
    inputRectangles.push_back(i4);
    inputRectangles.push_back(i5);
    // Intersections
    Rectangle r1 = Rectangle("1, 2", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r1);
    Rectangle r2 = Rectangle("1, 2, 3", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r2);
    Rectangle r3 = Rectangle("1, 2, 3, 4", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r3);
    Rectangle r4 = Rectangle("1, 2, 3, 4, 5", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r4);
    Rectangle r5 = Rectangle("1, 2, 3, 5", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r5);
    Rectangle r6 = Rectangle("1, 2, 4", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r6);
    Rectangle r7 = Rectangle("1, 2, 4, 5", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r7);
    Rectangle r8 = Rectangle("1, 2, 5", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r8);
    Rectangle r9 = Rectangle("1, 3", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r9);
    Rectangle r10 = Rectangle("1, 3, 4", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r10);
    Rectangle r11 = Rectangle("1, 3, 4, 5", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r11);
    Rectangle r12 = Rectangle("1, 3, 5", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r12);
    Rectangle r13 = Rectangle("1, 4", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r13);
    Rectangle r14 = Rectangle("1, 4, 5", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r14);
    Rectangle r15 = Rectangle("1, 5", 600, 600, 100, 100);
    expectedReturnRectangles.push_back(r15);
    Rectangle r16 = Rectangle("2, 3", 500, 500, 400, 400);
    expectedReturnRectangles.push_back(r16);
    Rectangle r17 = Rectangle("2, 3, 4", 500, 500, 400, 400);
    expectedReturnRectangles.push_back(r17);
    Rectangle r18 = Rectangle("2, 3, 4, 5", 500, 500, 400, 400);
    expectedReturnRectangles.push_back(r18);
    Rectangle r19 = Rectangle("2, 3, 5", 500, 500, 400, 400);
    expectedReturnRectangles.push_back(r19);
    Rectangle r20 = Rectangle("2, 4", 500, 500, 400, 400);
    expectedReturnRectangles.push_back(r20);
    Rectangle r21 = Rectangle("2, 4, 5", 500, 500, 400, 400);
    expectedReturnRectangles.push_back(r21);
    Rectangle r22 = Rectangle("2, 5", 500, 500, 400, 400);
    expectedReturnRectangles.push_back(r22);
    Rectangle r23 = Rectangle("3, 4", 400, 400, 600, 600);
    expectedReturnRectangles.push_back(r23);
    Rectangle r24 = Rectangle("3, 4, 5", 400, 400, 600, 600);
    expectedReturnRectangles.push_back(r24);
    Rectangle r25 = Rectangle("3, 5", 400, 400, 600, 600);
    expectedReturnRectangles.push_back(r25);
    Rectangle r26 = Rectangle("4, 5", 300, 300, 800, 800);
    expectedReturnRectangles.push_back(r26);
    auto testReturnIntersections = performIntersections(inputRectangles);
    EXPECT_EQ(expectedReturnRectangles, testReturnIntersections);
}

// Test case to check the boundary condition where intersections result in
// Rectangles of zero width or height, which should not be considered as
// intersections
TEST(PerformIntersectionsWithTouchingRectanglesShould,
     ReturnEmptyVectorOfIntersections) {
    std::vector<Rectangle> inputRectangles;
    std::vector<Rectangle> expectedReturnRectangles;
    Rectangle i1 = Rectangle("1", 100, 100, 100, 100);
    Rectangle i2 = Rectangle("2", 100, 200, 100, 100);
    Rectangle i3 = Rectangle("3", 200, 100, 100, 100);
    Rectangle i4 = Rectangle("4", 200, 200, 100, 100);
    inputRectangles.push_back(i1);
    inputRectangles.push_back(i2);
    inputRectangles.push_back(i3);
    inputRectangles.push_back(i4);
    auto testReturnIntersections = performIntersections(inputRectangles);
    
    EXPECT_EQ(expectedReturnRectangles, testReturnIntersections);
}

// Test case to check when given an input of disjoint Rectangles the resulting
// vector of intersections is empty
TEST(PerformIntersectionsWithDisjointNonTouchingRectanglesShould,
     ReturnEmptyVectorOfIntersections) {
    std::vector<Rectangle> inputRectangles;
    std::vector<Rectangle> expectedReturnRectangles;
    Rectangle i1 = Rectangle("1", 100, 100, 100, 100);
    Rectangle i2 = Rectangle("2", 100, 300, 100, 100);
    Rectangle i3 = Rectangle("3", 300, 100, 100, 100);
    Rectangle i4 = Rectangle("4", 400, 400, 100, 100);
    inputRectangles.push_back(i1);
    inputRectangles.push_back(i2);
    inputRectangles.push_back(i3);
    inputRectangles.push_back(i4);
    auto testReturnIntersections = performIntersections(inputRectangles);
    EXPECT_EQ(expectedReturnRectangles, testReturnIntersections);
}

// Test case to validate the correctness of intersections when Rectangles are in
// the negative coordinate space
TEST(PerformIntersectionsWithNegativeXYCoordinatesShould,
     ReturnVectorofIntersections) {
    std::vector<Rectangle> inputRectangles;
    std::vector<Rectangle> expectedReturnRectangles;
    Rectangle i1 = Rectangle("1", -100, -100, 80, 110);
    Rectangle i2 = Rectangle("2", 0, 0, 80, 250);
    Rectangle i3 = Rectangle("3", -50, -50, 100, 250);
    inputRectangles.push_back(i1);
    inputRectangles.push_back(i2);
    inputRectangles.push_back(i3);
    // Intersections
    Rectangle r1 = Rectangle("1, 3", -50, -50, 30, 60);
    Rectangle r2 = Rectangle("2, 3", 0, 0, 50, 200);
    expectedReturnRectangles.push_back(r1);
    expectedReturnRectangles.push_back(r2);
    auto testReturnIntersections = performIntersections(inputRectangles);
    EXPECT_EQ(expectedReturnRectangles, testReturnIntersections);
}

// Test case to validate the correctness of the program
TEST(PerformIntersectionsWith4SuchIntersectingRectanglesShould,
     ReturnVectorOf11Intersections) {
    std::vector<Rectangle> inputRectangles;
    std::vector<Rectangle> expectedReturnRectangles;
    Rectangle i1 = Rectangle("1", 100, 100, 80, 250);
    Rectangle i2 = Rectangle("2", 120, 200, 250, 250);
    Rectangle i3 = Rectangle("3", 140, 160, 100, 250);
    Rectangle i4 = Rectangle("4", 160, 140, 190, 350);
    inputRectangles.push_back(i1);
    inputRectangles.push_back(i2);
    inputRectangles.push_back(i3);
    inputRectangles.push_back(i4);
    // Intersections
    Rectangle r1 = Rectangle("1, 2", 120, 200, 60, 150);
    expectedReturnRectangles.push_back(r1);
    Rectangle r2 = Rectangle("1, 2, 3", 140, 200, 40, 150);
    expectedReturnRectangles.push_back(r2);
    Rectangle r3 = Rectangle("1, 2, 3, 4", 160, 200, 20, 150);
    expectedReturnRectangles.push_back(r3);
    Rectangle r4 = Rectangle("1, 2, 4", 160, 200, 20, 150);
    expectedReturnRectangles.push_back(r4);
    Rectangle r5 = Rectangle("1, 3", 140, 160, 40, 190);
    expectedReturnRectangles.push_back(r5);
    Rectangle r6 = Rectangle("1, 3, 4", 160, 160, 20, 190);
    expectedReturnRectangles.push_back(r6);
    Rectangle r7 = Rectangle("1, 4", 160, 140, 20, 210);
    expectedReturnRectangles.push_back(r7);
    Rectangle r8 = Rectangle("2, 3", 140, 200, 100, 210);
    expectedReturnRectangles.push_back(r8);
    Rectangle r9 = Rectangle("2, 3, 4", 160, 200, 80, 210);
    expectedReturnRectangles.push_back(r9);
    Rectangle r10 = Rectangle("2, 4", 160, 200, 190, 250);
    expectedReturnRectangles.push_back(r10);
    Rectangle r11 = Rectangle("3, 4", 160, 160, 80, 250);
    expectedReturnRectangles.push_back(r11);
    auto testReturnIntersections = performIntersections(inputRectangles);
    EXPECT_EQ(expectedReturnRectangles, testReturnIntersections);
}
