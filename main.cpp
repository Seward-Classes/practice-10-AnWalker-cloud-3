#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>

#include "Shape.h"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "Area: " << std::fixed << std::setprecision(4)
                  << shape->getArea() << "\n\n";
    }
}

int main() {
    std::ifstream file("shapes.txt");

    if (!file) {
        std::cout << "Error: file not found\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
        lineNum++;
        std::istringstream iss(line);

        std::string type;
        iss >> type;

        if (type == "rectangle") {
            double w, h;
            if (!(iss >> w >> h)) {
                std::cout << "Error on line " << lineNum << "\n";
                continue;
            }
            shapes.push_back(std::make_unique<Rectangle>(w, h));
        }
        else if (type == "circle") {
            double r;
            if (!(iss >> r)) {
                std::cout << "Error on line " << lineNum << "\n";
                continue;
            }
            shapes.push_back(std::make_unique<Circle>(r));
        }
        else {
            std::cout << "Unknown shape on line " << lineNum << "\n";
        }
    }

    printAllAreas(shapes);
    return 0;
}