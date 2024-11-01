#include <gtest/gtest.h>
#include <cmath>

#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Octagon.h"
#include "../include/figureArray.h"


TEST(triangle, default_constructor) {
    Triangle tr;
    Triangle trRef;
    ASSERT_TRUE(tr == trRef);
}

TEST(triangle, copy) {
    Point p1(1.0, 1.0), p2(2.0, 5.0), p3(5.0, 3.0);
    Triangle testTr(p1, p2, p3);
    Triangle tr;
    tr = std::move(testTr);
    ASSERT_TRUE(tr == testTr);
}

TEST(triangle, assignment) {
    Point p1(1.0, 1.0), p2(2.0, 5.0), p3(5.0, 3.0);
    Triangle testTr(p1, p2, p3);
    Triangle tr;
    tr = testTr;
    ASSERT_TRUE(tr == testTr);
}

TEST(triangle, rotation_center) {
    Point p1(2.0, -1.0), p2(-7.0, 3.0), p3(-1.0, -5.0);
    Triangle tr(p1, p2, p3);
    Point rotCenterRef(-2.0, -1.0);
    Point rotCenter = tr.center();
    ASSERT_TRUE(rotCenter == rotCenterRef);
}

TEST(triangle, area) {
    Point p1(1.0, 1.0), p2(2.0, 5.0), p3(5.0, 3.0);
    Triangle tr(p1, p2, p3);
    double area = static_cast<double>(tr);
    double areaRef = 7.0;
    EXPECT_NEAR(area, areaRef, 0.001);
}

TEST(square, default_constructor) {
    Square tr;
    Square trRef;
    ASSERT_TRUE(tr == trRef);
}

TEST(square, copy) {
    Point p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square testTr(p1, p2, p3, p4);
    Square tr;
    tr = std::move(testTr);
    ASSERT_TRUE(tr == testTr);
}

TEST(square, assignment) {
    Point p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square testTr(p1, p2, p3, p4);
    Square tr;
    tr = testTr;
    ASSERT_TRUE(tr == testTr);
}

TEST(square, rotation_center) {
    Point p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square tr(p1, p2, p3, p4);
    Point rotCenterRef(0.0, 0.0);
    Point rotCenter = tr.center();
    ASSERT_TRUE(rotCenter == rotCenterRef);
}

TEST(square, area) {
    Point p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square tr(p1, p2, p3, p4);
    double area = static_cast<double>(tr);
    double areaRef = 16.0;
    EXPECT_NEAR(area, areaRef, 0.001);
}

TEST(octagon, default_constructor) {
    Octagon tr;
    Octagon trRef;
    ASSERT_TRUE(tr == trRef);
}

TEST(octagon, copy) {
    Point p1(1.0, 2.0), p2(2.0, 3.0), p3(3.0, 2.0), p4(4.0, 1.0), p5(3.0, 0.0), p6(2.0, -1.0), p7(1.0, 0.0), p8(0.0, 1.0);
    Octagon testTr(p1, p2, p3, p4, p5 ,p6, p7, p8);
    Octagon tr;
    tr = std::move(testTr);
    ASSERT_TRUE(tr == testTr);
}

TEST(octagon, assignment) {
    Point p1(1.0, 2.0), p2(2.0, 3.0), p3(3.0, 2.0), p4(4.0, 1.0), p5(3.0, 0.0), p6(2.0, -1.0), p7(1.0, 0.0), p8(0.0, 1.0);
    Octagon testTr(p1, p2, p3, p4, p5 ,p6, p7, p8);
    Octagon tr;
    tr = testTr;
    ASSERT_TRUE(tr == testTr);
}

TEST(octagon, rotation_center) {
    Point p1(1.0, 2.0), p2(2.0, 3.0), p3(3.0, 2.0), p4(4.0, 1.0), p5(3.0, 0.0), p6(2.0, -1.0), p7(1.0, 0.0), p8(0.0, 1.0);
    Octagon tr(p1, p2, p3, p4, p5 ,p6, p7, p8);
    Point rotCenterRef(2.0, 1.0);
    Point rotCenter = tr.center();
    ASSERT_TRUE(rotCenter == rotCenterRef);
}

TEST(octagon, area) {
    Point p1(1.0, 2.0), p2(2.0, 3.0), p3(3.0, 2.0), p4(4.0, 1.0), p5(3.0, 0.0), p6(2.0, -1.0), p7(1.0, 0.0), p8(0.0, 1.0);
    Octagon tr(p1, p2, p3, p4, p5 ,p6, p7, p8);
    double area = static_cast<double>(tr);
    double areaRef = 8.0;
    EXPECT_NEAR(area, areaRef, 0.001);
}

TEST(figureArray, totalArea) {
    Array figures;
    Point p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square* square = new Square(p1, p2, p3, p4);
    Point p5(1.0, 1.0), p6(2.0, 5.0), p7(5.0, 3.0);
    Triangle* triangle = new Triangle(p5, p6, p7);
    double expectedTotalSquare = square->area() + triangle->area() ;

    figures.addFigure(square);
    figures.addFigure(triangle);

    ASSERT_TRUE(figures.totalArea() == expectedTotalSquare);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
