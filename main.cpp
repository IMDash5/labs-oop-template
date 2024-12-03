#include "DungeonMaster.hpp"

int main() {
    DungeonEditor editor;

    // Добавление NPC
    editor.addNPC("SlaveTrader", "Работорговец1", 100, 100);
    editor.addNPC("Druid", "Друид1", 120, 100);
    editor.addNPC("Orc", "Орк1", 130, 100);

    // Сохранение в файл
    editor.saveToFile("dungeon.txt");

    // Загрузка из файла
    editor.loadFromFile("dungeon.txt");

    // Печать всех NPC
    std::cout << "Список NPC:" << std::endl;
    editor.printNPCs();

    // Запуск боевого режима
    std::cout << "\nБой начинается!" << std::endl;
    editor.startCombat(50);

    // Результат
    std::cout << "\nПосле боя:" << std::endl;
    editor.printNPCs();

    return 0;
}
