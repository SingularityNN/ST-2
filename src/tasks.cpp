// Copyright 2025 UNN-CS Team
#include <cmath>
#include "tasks.h"
#include "circle.h"

double calculateEarthRopeGap() {
    double earthRadius = 6378100; 
    Circle earth(earthRadius);
    double ropeLength = earth.getFerence() + 1; 
    Circle newCircle(0);
    newCircle.setFerence(ropeLength);
    return newCircle.getRadius() - earthRadius;
}

double calculatePoolCost() {
    double poolRadius = 3; 
    double pathWidth = 1; 
    double concreteCostPerSquareMeter = 1000; 
    double fenceCostPerMeter = 2000; 

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double totalConcreteCost = pathArea * concreteCostPerSquareMeter;
    double totalFenceCost = fenceLength * fenceCostPerMeter;

    return totalConcreteCost + totalFenceCost;
}
