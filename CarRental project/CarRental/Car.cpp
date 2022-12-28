#include "Car.h"
#include<string>
#include<vector>

using namespace std;


Car::Car(string brand, string model, string car_id, string color, string production_year)          /*This constructor is used while the new car is added to list*/
{
    this->brand = brand;
    this->model = model;
    this->car_id = car_id;
    this->color = color;
    this->production_year = production_year;
}

Car::Car(string s)          /*This constructor takes string from the file, it "cuts" them and assign to proper variables*/
{
    vector<int> vec;
    for (int i = 0; i <= s.size(); i++) if (s[i] == ' ') vec.push_back(i);
    brand = s.substr(0, vec[0]);
    model = s.substr(vec[0] + 1, vec[1] - 1 - (vec[0]));
    car_id = s.substr(vec[1] + 1, vec[2] - 1 - vec[1]);
    color = s.substr(vec[2] + 1, vec[3] - 1 - vec[2]);
    production_year = s.substr(vec[3] + 1, s.size() - 1);
}