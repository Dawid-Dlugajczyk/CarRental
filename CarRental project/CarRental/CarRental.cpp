#include <iostream>
#include<string>
#include "Car.h"
#include "User.h"
#include "Rental.h"
#include "List.h"
#include<fstream>
#include<algorithm>
#include <stdlib.h> 
#include <conio.h>


int main()
{
    string name, surname, id_number, pesel, i, brand, model, car_id, color, production_year;
    Rental r;
    User usr;
    Car c;
    list l;
    string s;
    fstream plik, file;
    vector<string> v;
    vector<string> vtr;



    plik.open("Users.txt", ios::in);
    if (plik.is_open())
    {
        while (!plik.eof())
        {
            getline(plik, s);
            if (s == "")continue;
            v.push_back(s);
        }
        for (auto a : v)  r.newUser(a);
        r.showAllUsers();
    }
    else cout << "File was not open" << endl;


    file.open("Cars.txt", ios::in);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, s);
            if (s == "")continue;
            vtr.push_back(s);
        }
        for (auto a : vtr)  r.newCar(a);
        r.showAllCars();
    }
    else cout << "File was not open" << endl;

    l.ReadFile();

    char var;
    do
    {

        cout << "Choose an option." << "\n"
            << "Press: \n"
            << "0 - Show rented cars. \n"
            << "1 - Rent a Car. \n"
            << "2 - To add a new User. \n"
            << "3 - To add a new Car.\n"
            << "4 - To see all Users\n"
            << "5 - To see all Cars\n"
            << "6 - To delete User\n"
            << "7 - To delete Car\n"
            << "8 - To exit menu\n"
            << "9 - Hand over the Car" << endl;
        cin >> var;
        if ((int)var < 48 || (int)var>57 || to_string((int)var - '0').size() > 1)
        {
            cout << "Enter the number again" << endl;
            var = 0;
            continue;
        }
        else
        {
            switch (var)
            {
            case '0':
            {
                l.ShowList();
            }
            break;

            case '1':
            {
                cout << "Type user id:";
                cin >> id_number;
                if (r.find_user(id_number) == nullptr)
                {
                    cout << "There is no User with that id number." << endl;
                    break;
                }

                cout << "\nType car id:";
                cin >> car_id;
                cout << endl;

                if (r.find_car(car_id) == nullptr)
                {
                    cout << "There is no Car with that id number." << endl;
                    break;
                }

                    l.new_Rent(car_id, id_number);
                    
                }
                break;

            case '2':
            {
                cout << "Enter: \n";
                cout << "name: ";
                cin >> name;
                cout << "surname: ";
                cin >> surname;
                cout << "id_number: ";
                cin >> id_number;
                if (r.find_user(id_number) != nullptr)
                {
                    cout << "User with that id is already in the system" << endl;
                    break;
                }
                cout << "pesel: ";
                cin >> pesel;
                r.newUser(name, surname, id_number, pesel);
                ofstream plik;
                plik.open("Users.txt", ios_base::app);
                plik << name + " " + surname + " " + id_number + " " + pesel + "\n";
                plik.close();
            }
            break;

            case '3':
            {
                cout << "Enter: \n";
                cout << "Brand: ";
                cin >> brand;
                cout << "Model: ";
                cin >> model;
                cout << "car id number: ";
                cin >> car_id;
                if (r.find_car(car_id) != nullptr) 
                {
                    cout << "Car with that id is already in the system" << endl;
                    break;
                }
                cout << "color: ";
                cin >> color;
                cout << "Year of production: ";
                cin >> production_year;
                r.newCar(brand, model, car_id, color, production_year);
                ofstream file;
                file.open("Cars.txt", ios_base::app);
                file << brand + " " + model + " " + car_id + " " + color + " " + production_year + "\n";
                file.close();
            }
            break;

            case '4':
            {
                r.showAllUsers();
            }
            break;

            case '5':
            {
                r.showAllCars();

            }
            break;

            case '6':
            {
                cout << "Type an id number of accout that you want to delete: ";
                cin >> i;
                r.deleteUser(i);
                ofstream plik;
                plik.open("Users.txt", ios::out);
                if (plik.is_open())
                {
                    for (auto a : r.getList()) plik << *a;
                }
                else cout << "Error" << endl;
                plik.close();
            }
            case '7':
            {
                cout << "Type an id number of car that you want to delete: ";
                cin >> i;
                r.deleteCar(i);
                ofstream file;
                file.open("Cars.txt", ios::out);
                if (file.is_open())
                {
                    if (plik.is_open())
                    {
                        for (auto a : r.getList1()) plik << *a;
                    }
                }
                else cout << "Error" << endl;
                file.close();

            }

            case'9':
            {
                if (l.First == nullptr)
                {
                    cout << "The list is empty";
                    break;
                }
                int n;
                cout << "Type number of rention which has to be removed: ";
                cin >> n;
                    l.delete_Rent(n);
            }
                break;
            }
            }



        } while (var != '8');


        ofstream p, f;

        p.open("Users.txt", ios::out);
        if (p.is_open())
        {
            for (auto a : r.getList()) p << *a;
        }
        else cout << "Error" << endl;

        f.open("Cars.txt", ios::out);
        if (f.is_open())
        {
            for (auto a : r.getList1()) f << *a;
        }
        else cout << "Error" << endl;

        l.WriteFile();

        f.close();
        p.close();

        usr.~User();
        c.~Car();
        r.~Rental();


        return 0;
    }

