#include "file_processor.h"
#include "order.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <windows.h>

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX_ORDERS = 100;  // Максимальное количество заказов
    ORDER* orders[MAX_ORDERS];
    int numOrders = 0;

    FileProcessor fileProcessor;

    try {
        char payerToSearch[50];
        int choice;

        do {
            system("cls");
            std::cout << "----- MENU -----\n";
            std::cout << "1. Add Order\n";
            std::cout << "2. Display Orders (sorted by payer account)\n";
            std::cout << "3. Search and Display Amount by Payer Account\n";
            std::cout << "4. Read Text from File\n";  // Новый пункт меню
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                std::cout << "Enter details for the new Order:\n";
                orders[numOrders] = new ORDER();
                std::cin >> (*orders[numOrders]);
                numOrders++;
                break;
            }
            case 2: {
                // Сортировка заказов по расчетным счетам плательщиков
                std::sort(orders, orders + numOrders, [](ORDER* a, ORDER* b) {
                    return strcmp(a->getPayerAccount(), b->getPayerAccount()) < 0;
                    });

                // Вывод отсортированных заказов
                std::cout << "\n--- Sorted Orders ---\n";
                for (int i = 0; i < numOrders; ++i) {
                    std::cout << (*orders[i]);
                }
                break;
            }
            case 3: {
                std::cout << "Enter payer account to search: ";
                std::cin >> payerToSearch;

                // Вывод информации о сумме, снятой с расчетного счета плательщика
                bool found = false;
                for (int i = 0; i < numOrders; ++i) {
                    if (strcmp(orders[i]->getPayerAccount(), payerToSearch) == 0) {
                        std::cout << "Amount withdrawn from payer's account: "
                            << orders[i]->getAmount() << " rubles\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    throw std::runtime_error("Payer account not found.");
                }
                break;
            }
            case 4: {
                // Чтение текста из файла и обработка
                std::cout << "Enter the name of the file: ";
                std::string filename;
                std::cin >> filename;

                fileProcessor = FileProcessor(filename.c_str());
                std::cout << "FileProcessor object created.\n";
                break;
            }
            case 5: {
                // Освобождение памяти перед выходом из программы
                for (int i = 0; i < numOrders; ++i) {
                    delete orders[i];
                }
                std::cout << "Exiting the program.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
            system("pause");
        } while (choice != 5);

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}