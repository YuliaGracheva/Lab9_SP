#include <iostream>
#include <string>
#include "flight.h"
#include "Tree.h"
#pragma once

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    Tree tree;

    tree.addFlight("RUS", "USA", 1, 1);
    tree.addFlight("JAP", "RUS", 2 ,2);
    tree.addFlight("USA", "JAP", 3, 3);
    tree.addFlight("AM", "CH", 4, 4);

    cout << "1) добавление. \n 2) поиск \n 3) удаление \n 4) вывод всех \n 5) выход";
    cout << endl;

    string DepartureAirport = "";
    string ArrivalAirport;
    int departureHour =0;
    int departureMinute =0;
    int choise =0;
    bool exit = false;
    while (exit == false) {
        cout << "Выберите число: ";
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Введите аиропорт отправления: ";
            cin >> DepartureAirport;
            cout << "Введите аиропорт прибытия: ";
            cin >> ArrivalAirport;
            cout << "Введите часы отправления: ";
            cin >> departureHour;
            cout << "Введите минуты отправления: ";
            cin >> departureMinute;
            tree.addFlight(DepartureAirport, ArrivalAirport, departureHour, departureMinute);
            cout << "Добавлено\n";
            break;

        case 2:
            cout << "Введите аиропорт отправления: ";
            cin >> DepartureAirport;
            cout << "Введите аиропорт прибытия: ";
            cin >> ArrivalAirport;
            if (tree.findFlight(DepartureAirport, ArrivalAirport, departureHour, departureMinute)) cout << "Есть\n"; else cout << "Нет\n";
            break;

        case 3:
            cout << "Введите аиропорт отправления: ";
            cin >> DepartureAirport;
            cout << "Введите аиропорт прибытия: ";
            cin >> ArrivalAirport;
            tree.removeFlight(DepartureAirport, ArrivalAirport, departureHour, departureMinute); cout << DepartureAirport << " " << ArrivalAirport << " удален\n";
            break;

        case 4:
            cout << "Все рейсы." << endl;
            tree.printAllFlights();
            break;

        case 5:
            cout << "Выход из приложения..." << endl;
            exit = true;
            break;

        default: "Неверный ввод";
        }
    }

    system("pause");
    return 0;
}