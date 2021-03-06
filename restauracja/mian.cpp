#include <iostream>
#include <windows.h>

#include "global_variables.h"
#include "can_be_delivered.h"
#include "pick_from_menu.h"

using namespace std;

string user_name, user_surname, delivery_hour, city, street, house_number;
int table_number, delivery_type;

//funcion that handle esc press
DWORD WINAPI CheckEscape(LPVOID lpParam) {
    while (GetAsyncKeyState(VK_ESCAPE) == 0) {
    }

    system("cls");

    cout << "Dziekujemy za skorzystanie z aplikacji. Do zobaczenia!" << endl;

    exit(0);

}

int main()
{
    //create thread for chandling esc click and exit app after that
    CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);

    cout << "Restauracja u Eryka, Mateusza, Jakuba i Jakuba" << endl;
    cout << "Adres:" << endl;
    cout << "Miasto: XYZ" << endl;
    cout << "Ulica: XYZ 00" << endl;

    cout << endl;

    do {
        cout << "Wprowadz swoje Imie: ";
        cin >> user_name;

        cout << "Wprowadz swoje Nazwisko: ";
        cin >> user_surname;

        if (user_name.length() <= 0 || user_surname.length() <= 0) {
            system("cls");

            cout << "Wprowadzono niepoprawne dane, prosze wprowadzic ponownie" << endl;

            cin.get();
            cin.get();

            system("cls");
        }

    } while (user_name.length() <= 0 || user_surname.length() <= 0);

    do {
        system("cls");
        cout << "Dostepne metody dostawy:" << endl;
        cout << "1) Odbior na miejscu" << endl;
        cout << "2) Dostawa do domu" << endl;

        cout << endl;

        cout << "Wybierz metode dostawy z dostepnych powyzej: ";
        cin >> delivery_type;

        system("cls");

        switch (delivery_type) {
        case 1:
                cout << "Prosze podac number stolika: ";
                cin >> table_number;
                
                system("cls");

                pickFromMenu();
            break;
        case 2:
            do {
                cout << "Wprowadz miasto, do ktorego mamy wyslac zamowienie: ";
                cin >> city;
            } while (city.length() <= 0);

            system("cls");

            do {
                cout << "Wprowadz ulice, na ktora mamy wyslac zamowienie: ";
                cin >> street;
            } while (street.length() <= 0);

            system("cls");

            do {
                cout << "Wprowadz numer domu, na ktory mamy wyslac zamowienie: ";
                cin >> house_number;
            } while (house_number.length() <= 0);

            system("cls");

            do {
                cout << "Godziny pracy restauracji:" << endl;
                cout << "Pn-Pt: " << working_days_from << " - " << working_days_to << endl;
                cout << "Sb-Nd: " << weekend_days_from << " - " << weekend_days_to << endl;

                cout << endl;

                cout << "Prosze wprowadzic godzine dostawy w formacie [hh:mm]: ";
                cin >> delivery_hour;
                
                if (!canBeDelivered(delivery_hour)) {
                    system("cls");

                    cout << "Wprowadzono niepoprawna godzine dostawy, prosze wprowadzic godzine ponownie." << endl;
                    
                    cin.get();
                    cin.get();

                    system("cls");
                }

            } while (!canBeDelivered(delivery_hour));

            system("cls");
            
            pickFromMenu();

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

