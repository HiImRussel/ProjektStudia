#include <iostream>
#include "global_variables.h"
#include "can_be_delivered.h"
#include "pick_from_menu.h"

using namespace std;

string user_name;
string user_surname;
int table_number;
int delivery_type;
string delivery_hour;

int main()
{
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
                cout << "Prosze podac number stolika: ";
                cin >> table_number;
                
                system("cls");

                pickFromMenu();
            break;
        case 2:
            do {
                cout << "Godziny pracy restauracji:" << endl;
                cout << "Pn-Pt: " << working_days_from << " - " << working_days_to << endl;
                cout << "Sb: " << weekend_days_from << " - " << weekend_days_to << endl;

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

