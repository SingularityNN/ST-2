// Copyright 2025 UNN-CS Team
#include <cstdint>
#include <cmath>
#include "circle.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double r) {
    setRadius(abs(r));
}

void Circle::setRadius(double r) {
    radius = abs(r);
    updateFerence();
    updateArea();
}

void Circle::setFerence(double f) {
    ference = abs(f);
    radius = f / (2 * M_PI);
    updateArea();
}

void Circle::setArea(double a) {
    area = abs(a);
    radius = sqrt(a / M_PI);
    updateFerence();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

void Circle::updateFerence() {
    ference = 2 * M_PI * radius;
}

void Circle::updateArea() {
    area = M_PI * radius * radius;
}
