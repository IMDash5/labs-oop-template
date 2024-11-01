#include <iostream>
#include "Point.h"
#include "Figure.h" 
#include "Triangle.h"
#include "Square.h"
#include "Octagon.h" 
#include "figureArray.h"

int main() {
    Array figureArray;

    int choice;
    while (true) {
        std::cout << "Выберите фигуру для добавления (1 - Треугольник, 2 - Восьмиугольник, 3 - Квадрат, 0 - Выход): ";
        std::cin >> choice;
        if (choice == 0) break;

        if (choice == 1) {
            Triangle* triangle = new Triangle();
            std::cin >> *triangle;
            figureArray.addFigure(triangle);
        } else if (choice == 2) {
            Octagon* octagon = new Octagon();
            std::cin >> *octagon;
            figureArray.addFigure(octagon);}
        else if (choice == 3) {
            Square* square = new Square();
            std::cin >> *square;
            figureArray.addFigure(square);
        } else {
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