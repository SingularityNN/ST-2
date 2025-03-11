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

TEST(CircleTest, NegativeRadius) {
    Circle c(5);
    c.setRadius(-10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e12);
}

TEST(CircleTest, SetFerenceNegative) {
    Circle c(5);
    c.setFerence(-10);
    EXPECT_DOUBLE_EQ(c.getFerence(), 10);
}

TEST(CircleTest, SetAreaNegative) {
    Circle c(5);
    c.setArea(-100);
    EXPECT_DOUBLE_EQ(c.getArea(), 100);
}

TEST(CircleTest, SetRadiusFromArea) {
    Circle c(0);
    c.setArea(78.53981633974483);
    EXPECT_NEAR(c.getRadius(), 5, 0.1);
}

TEST(CircleTest, SetRadiusFromFerence) {
    Circle c(0);
    c.setFerence(31.41592653589793);
    EXPECT_NEAR(c.getRadius(), 5, 0.1);
}

TEST(EarthRopeTest, GapCalculation) {
    double gap = calculateEarthRopeGap();
    EXPECT_NEAR(gap, 0.159, 0.1);
}

TEST(EarthRopeTest, SmallEarthRadius) {
    double smallRadius = 1000;
    Circle earth(smallRadius);
    double ropeLength = earth.getFerence() + 1;
    Circle newCircle(0);
    newCircle.setFerence(ropeLength);
    double gap = newCircle.getRadius() - smallRadius;
    EXPECT_NEAR(gap, 0.159, 0.1);
}

TEST(EarthRopeTest, LargeEarthRadius) {
    double largeRadius = 1e6;
    Circle earth(largeRadius);
    double ropeLength = earth.getFerence() + 1;
    Circle newCircle(0);
    newCircle.setFerence(ropeLength);
    double gap = newCircle.getRadius() - largeRadius;
    EXPECT_NEAR(gap, 0.159, 0.1);
}

TEST(EarthRopeTest, ZeroRopeLength) {
    double earthRadius = 6378100;
    Circle earth(earthRadius);
    double ropeLength = earth.getFerence();
    Circle newCircle(0);
    newCircle.setFerence(ropeLength);
    double gap = newCircle.getRadius() - earthRadius;
    EXPECT_DOUBLE_EQ(gap, 0);
}

TEST(PoolCostTest, CostCalculation) {
    double cost = calculatePoolCost();
    EXPECT_NEAR(cost, 72257, 0.1);
}

TEST(PoolCostTest, SmallPoolRadius) {
    double smallRadius = 1;
    double pathWidth = 1;
    Circle pool(smallRadius);
    Circle poolWithPath(smallRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    double totalConcreteCost = pathArea * 1000;
    double totalFenceCost = fenceLength * 2000;
    double totalCost = totalConcreteCost + totalFenceCost;
    EXPECT_NEAR(totalCost, 15708, 0.1);
}

TEST(PoolCostTest, LargePoolRadius) {
    double largeRadius = 10;
    double pathWidth = 1;
    Circle pool(largeRadius);
    Circle poolWithPath(largeRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    double totalConcreteCost = pathArea * 1000;
    double totalFenceCost = fenceLength * 2000;
    double totalCost = totalConcreteCost + totalFenceCost;
    EXPECT_NEAR(totalCost, 144513, 0.1);
}

TEST(PoolCostTest, ZeroPathWidth) {
    double poolRadius = 3;
    double pathWidth = 0;
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    double totalConcreteCost = pathArea * 1000;
    double totalFenceCost = fenceLength * 2000;
    double totalCost = totalConcreteCost + totalFenceCost;
    EXPECT_NEAR(totalCost, 37699, 0.1);
}
