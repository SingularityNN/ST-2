#include "tasks.h"
#include "circle.h"
#include <cmath>

double calculateEarthRopeGap() {
    double earthRadius = 6378100; // Радиус Земли в метрах
    Circle earth(earthRadius);
    double ropeLength = earth.getFerence() + 1; // Добавляем 1 метр к длине верёвки
    Circle newCircle(0);
    newCircle.setFerence(ropeLength);
    return newCircle.getRadius() - earthRadius;
}

double calculatePoolCost() {
    double poolRadius = 3; // Радиус бассейна в метрах
    double pathWidth = 1; // Ширина дорожки в метрах
    double concreteCostPerSquareMeter = 1000; // Стоимость бетона за квадратный метр
    double fenceCostPerMeter = 2000; // Стоимость ограды за погонный метр

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double totalConcreteCost = pathArea * concreteCostPerSquareMeter;
    double totalFenceCost = fenceLength * fenceCostPerMeter;

    return totalConcreteCost + totalFenceCost;
}