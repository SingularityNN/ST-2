// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

TEST(CircleTest, Radius) {
    Circle c(5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5);
    c.setRadius(10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10);
}

TEST(CircleTest, Ference) {
    Circle c(5);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5);
    c.setFerence(31.41592653589793);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5);
}

TEST(CircleTest, Area) {
    Circle c(5);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25);
    c.setArea(78.53981633974483);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5);
}

TEST(EarthRopeTest, GapCalculation) {
    double gap = calculateEarthRopeGap();
    EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(PoolCostTest, CostCalculation) {
    double cost = calculatePoolCost();
    EXPECT_NEAR(cost, 72257, 0.001);
}


