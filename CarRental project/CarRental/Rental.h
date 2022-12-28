#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "Car.h"
#include <fstream>


using namespace std;

class Rental
{

	vector<User*> Users;
	vector<Car*> Cars;

public:
    void newUser(string name, string surname, string id_number, string pesel);
    void newUser(string s);
    void deleteUser(string id);
    User* find_user(string id_number);
    void showAllUsers();

    void newCar(string brand, string model, string car_id, string color, string production_year);
    void newCar(string s);
    Car* find_car(string car_id);
    void deleteCar(string id);
    void showAllCars();


    vector<User*>& getList()
    {
        return Users;
    }
    vector<Car*>& getList1()
    {
        return Cars;
    }
    
};