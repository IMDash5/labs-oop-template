#include <iostream>
#include "src/Point.cpp"
#include "src/Triangle.cpp"
#include "src/Square.cpp"
#include "src/Octagon.cpp"
#include "src/figureArray.cpp"
#include "include/Octagon.h"
#include "include/Point.h"
#include "include/Figure.h"
#include "include/Square.h"





int main() {
    Array<Figure<double>> figureArray;

    int choice;
    while (true) {
        std::cout << "Выберите фигуру для добавления (1 - Треугольник, 2 - Восьмиугольник, 3 - Квадрат, 0 - Выход): ";
        std::cin >> choice;
        if (choice == 0) break;

        if (choice == 1) {
            Triangle<double> triangle;
            std::cin >> triangle;
            figureArray.addFigure(std::make_shared<Triangle<double>>(triangle));}
        else if (choice == 2) {
            Octagon<double> octagon;
            std::cin >> octagon;
            figureArray.addFigure(std::make_shared<Octagon<double>>(octagon));}
        else if (choice == 3) {
            Square<double> square;
            std::cin >> square;
            figureArray.addFigure(std::make_shared<Square<double>>(square));
        } 
        else {
            std::cout << "Неверный выбор." << std::endl;
        }
    }
    figureArray.printFigures();
    
    std::cout << "Общая площадь фигур: " << figureArray.totalArea() << std::endl;

    int indexToRemove;
    std::cout << "Введите индекс фигуры для удаления: ";
    std::cin >> indexToRemove;
    figureArray.removeFigure(indexToRemove - 1);

    figureArray.printFigures();

    return 0;
}