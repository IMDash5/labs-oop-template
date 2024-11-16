#include <gtest/gtest.h>
#include "../src/Point.cpp"
#include "../src/Triangle.cpp"
#include "../src/Square.cpp"
#include "../src/Octagon.cpp"
#include "../src/figureArray.cpp"

TEST(triangle, default_constructor) {
    Triangle<double> tr;
    Triangle<double> trRef;
    ASSERT_TRUE(tr == trRef);
}

TEST(triangle, copy) {
    Point<double> p1(1.0, 1.0), p2(2.0, 5.0), p3(5.0, 3.0);
    Triangle<double> testTr(p1, p2, p3);
    Triangle<double> tr;
    tr = std::move(testTr);
    EXPECT_NO_THROW();
}

TEST(triangle, assignment) {
    Point<double> p1(1.0, 1.0), p2(2.0, 5.0), p3(5.0, 3.0);
    Triangle<double> testTr(p1, p2, p3);
    Triangle<double> tr;
    tr = testTr;
    ASSERT_TRUE(tr == testTr);
}

TEST(triangle, rotation_center) {
    Point<double> p1(2.0, -1.0), p2(-7.0, 3.0), p3(-1.0, -5.0);
    Triangle<double> tr(p1, p2, p3);
    Point<double> rotCenterRef(-2.0, -1.0);
    Point<double> rotCenter = tr.center();
    ASSERT_TRUE(rotCenter == rotCenterRef);
}

TEST(triangle, area) {
    Point<double> p1(1.0, 1.0), p2(2.0, 5.0), p3(5.0, 3.0);
    Triangle<double> tr(p1, p2, p3);
    double area = static_cast<double>(tr);
    double areaRef = 7.0;
    EXPECT_NEAR(area, areaRef, 0.001);
}

TEST(square, default_constructor) {
    Square<double> tr;
    Square<double> trRef;
    ASSERT_TRUE(tr == trRef);
}

TEST(square, copy) {
    Point<double> p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square<double> testTr(p1, p2, p3, p4);
    Square<double> tr;
    tr = std::move(testTr);
    EXPECT_NO_THROW();
}

TEST(square, assignment) {
    Point<double> p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square<double> testTr(p1, p2, p3, p4);
    Square<double> tr;
    tr = testTr;
    ASSERT_TRUE(tr == testTr);
}

TEST(square, rotation_center) {
    Point<double> p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square<double> tr(p1, p2, p3, p4);
    Point<double> rotCenterRef(0.0, 0.0);
    Point<double> rotCenter = tr.center();
    ASSERT_TRUE(rotCenter == rotCenterRef);
}

TEST(square, area) {
    Point<double> p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    Square <double>tr(p1, p2, p3, p4);
    double area = static_cast<double>(tr);
    double areaRef = 16.0;
    EXPECT_NEAR(area, areaRef, 0.001);
}

TEST(octagon, default_constructor) {
    Octagon<double> tr;
    Octagon<double> trRef;
    ASSERT_TRUE(tr == trRef);
}

TEST(octagon, copy) {
    Point<double> p1(1.0, 2.0), p2(2.0, 3.0), p3(3.0, 2.0), p4(4.0, 1.0), p5(3.0, 0.0), p6(2.0, -1.0), p7(1.0, 0.0), p8(0.0, 1.0);
    Octagon<double> testTr(p1, p2, p3, p4, p5 ,p6, p7, p8);
    Octagon <double>tr;
    tr = std::move(testTr);
    EXPECT_NO_THROW();
}

TEST(octagon, assignment) {
    Point<double> p1(1.0, 2.0), p2(2.0, 3.0), p3(3.0, 2.0), p4(4.0, 1.0), p5(3.0, 0.0), p6(2.0, -1.0), p7(1.0, 0.0), p8(0.0, 1.0);
    Octagon<double> testTr(p1, p2, p3, p4, p5 ,p6, p7, p8);
    Octagon<double> tr;
    tr = testTr;
    ASSERT_TRUE(tr == testTr);
}

TEST(octagon, rotation_center) {
    Point<double> p1(1.0, 2.0), p2(2.0, 3.0), p3(3.0, 2.0), p4(4.0, 1.0), p5(3.0, 0.0), p6(2.0, -1.0), p7(1.0, 0.0), p8(0.0, 1.0);
    Octagon<double> tr(p1, p2, p3, p4, p5 ,p6, p7, p8);
    Point<double> rotCenterRef(2.0, 1.0);
    Point<double> rotCenter = tr.center();
    ASSERT_TRUE(rotCenter == rotCenterRef);
}

TEST(octagon, area) {
    Point<double> p1(1.0, 2.0), p2(2.0, 3.0), p3(3.0, 2.0), p4(4.0, 1.0), p5(3.0, 0.0), p6(2.0, -1.0), p7(1.0, 0.0), p8(0.0, 1.0);
    Octagon<double> tr(p1, p2, p3, p4, p5 ,p6, p7, p8);
    double area = static_cast<double>(tr);
    double areaRef = 8.0;
    EXPECT_NEAR(area, areaRef, 0.001);
}

TEST(figureArray, totalArea) {
    Array<Figure<double>> figures;
    Point<double> p1(2.0, 2.0), p2(-2.0, 2.0), p3(2.0, -2.0), p4(-2.0, -2.0);
    auto square = std::make_shared<Square<double>>(p1, p2, p3, p4);
    Point<double> p5(1.0, 1.0), p6(2.0, 5.0), p7(5.0, 3.0);
    auto triangle = std::make_shared<Triangle<double>>(p5, p6, p7);
    double expectedTotalSquare = square->area() + triangle->area() ;

    figures.addFigure(std::move(square));
    figures.addFigure(std::move(triangle));

    ASSERT_TRUE(figures.totalArea() == expectedTotalSquare);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
