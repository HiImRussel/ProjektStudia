#include <iostream>
#include "global_variables.h"
#include "can_be_delivered.h" 

using namespace std;

string user_name;
int table_number;

int main()
{
    int delivery_type;
    string delivery_hour;

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
            do {
                cout << "Prosze podac number stolika: ";
                cin >> table_number;

                if (!isdigit(table_number)) {
                    cout << endl;

                    cout << "Prosze wprowadzic odpowiedni numer stolika" << endl;
                    
                    cin.get();
                    cin.get();
                }

            } while (!isdigit(table_number));
            break;
        case 2:
            cout << "Godziny pracy restauracji:" << endl;
            cout << "Pn-Pt: " << working_days_from <<" - "<< working_days_to << endl;
            cout << "Sb: " << weekend_days_from << " - " << weekend_days_to << endl;

            cout << endl;

            cout << "Prosze wprowadzic godzine dostawy w formacie [hh:mm]: ";
            cin >> delivery_hour;

            canBeDelivered(delivery_hour);

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

