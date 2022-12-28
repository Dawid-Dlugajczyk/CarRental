#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Car
{
    //vector<Car*> Cars;
private:
    string brand;
    string model;
    string car_id;
    string color;
    string production_year;
public:
    Car() = default;
    Car(string brand, string model, string car_id, string color, string production_year);
    Car(string s);
    ~Car();
    friend ostream& operator<<(ostream & os, const Car & c);
    string get_id()
    {
        return this->car_id;
    };

    string get_brand()
    {
        return this->brand;
    }
    string get_model()
    {
        return this->model;
    }
    string get_color()
    {
        return this->color;
    }
    string get_production_year()
    {
        return this->production_year;
    }

    
/*
    vector<Car*>& getList()
    {
        return Cars;
    }
    */
};

