#pragma once
#include <iostream>

class Shape {
public:
    virtual double getArea() const = 0;   // pure virtual
    virtual void display() const {
        std::cout << "Shape\n";
    }

    virtual ~Shape() = default;
};
#pragma once
#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double getArea() const = 0;

    virtual void display() const {
        std::cout << "Shape\n";
    }

    virtual ~Shape() = default;
};

// ---------------- Rectangle ----------------
class Rectangle : public Shape {
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    void display() const override {
        std::cout << "Rectangle (" << width << " x " << height << ")\n";
    }
};

// ---------------- Circle ----------------
class Circle : public Shape {
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        std::cout << "Circle (radius: " << radius << ")\n";
    }
};