#include <iostream>
#include "global_variables.h"

using namespace std;

string user_name;

int main()
{
    int delivery_type;

    cout << "Restauracja u Eryka, Mateusza, Jakuba i Jakuba" << endl;
    cout << "Adres:" << endl;
    cout << "Miasto: XYZ" << endl;
    cout << "Ulica: XYZ 00" << endl;

    cout << endl;

    cout << "Wprowadz swoje Imie i Nazwisko: ";
    cin >> user_name;

    system("cls");

    do {
        cout << "Dostepne metody dostawy:" << endl;
        cout << "1) Odbior na miejscu" << endl;
        cout << "2) Dostawa do domu" << endl;

        cout << endl;

        cout << "Wybierz metode dostawy z dostepnych powyzej: ";
        cin >> delivery_type;

        system("cls");

        switch (delivery_type) {
        case 1:
            cout << "1";
            break;
        case 2:
            cout << "2";
            break;
        default:
            cout << "Nie rozpoznano metody dostawy, prosze wprowadzic ponownie";

            cin.get();
            cin.get();

            system("cls");
            break;
        }
    } while (delivery_type != 1 && delivery_type != 2);
}

