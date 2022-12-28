#include "Rental.h"
#include <string>
#include <fstream>




void Rental::newUser(string s)         /*This method puts new object to vector*/
{
    Users.push_back(new User(s));
}

void Rental::newUser(string name, string surname, string id_number, string pesel)          /*This method also puts new object to vector*/
{
    Users.push_back(new User(name, surname, id_number, pesel));
}
    
User::~User()
{

}

ostream& operator<<(ostream& os, const User& a)          /*Operator overloading*/
{
    os << a.name << " " << a.surname << " " << a.id_number << " " << a.pesel << endl;
    return os;
}

User* Rental::find_user(string id_number)           /*This method is searching for object in vector, which id_number is the same as parameter passed to function*/
{
    auto it = Users.begin();
    for (it; it < Users.end(); it++)
    {
        User* ptr;
        ptr = *it;
        if (ptr->get_id() == id_number) return ptr;
    }
    return nullptr;
}
void Rental::showAllUsers()             /*This method is used to read all data about Users from (txt.) file and print them on the screen.*/
{
    for (auto a : Users)
        cout << "name: " << a->get_name() << "\t surname: "
        << a->get_surname() << "\t id_number: " << a->get_id()
        << "\t pesel: " << a->get_pesel() << endl;
}

void Rental::deleteUser(string id)         /*This function is used to delete an account chosen by user*/
{
    int position = -1;
    for (int i = 0; i < Users.size(); i++) if (Users[i]->get_id() == id)
    {
        cout << Users[i]->get_id() << " " << id << endl;
        position = i;
        break;
    }
    if (position == -1)
    {
        cout << "The account with that id does not exist, try again." << endl;
        return;
    }
    Users.erase(Users.begin() + position);
}


//---------------------------------------------------------------------------------------------



void Rental::newCar(string s)         /*This method puts new object to vector*/
{
    Cars.push_back(new Car(s));
}

void Rental::newCar(string brand, string model, string car_id, string color, string production_year)       /*This method also puts new object to vector*/
{
    Cars.push_back(new Car(brand, model, car_id, color, production_year));
}

Car::~Car()
{

}

ostream& operator<<(ostream& os, const Car& a)          /*Operator overloading*/
{
    os << a.brand << " " << a.model << " " << a.car_id << " " << a.color << " " << a.production_year << endl;
    return os;
}

void Rental::showAllCars()             /*This method is used to read all data about Cars from (txt.) file and print them on the screen.*/
{
    cout << "--------------------------------------------" << endl;
    for (auto a : Cars)
        cout << "brand: " << a->get_brand() << "\t model: "
        << a->get_model() << "\t car_id: " << a->get_id()
        << "\t color: " << a->get_color() << "\t production year: "
        << a->get_production_year() << "\t" << endl;
}

Car* Rental::find_car(string car_id)           /*This method is searching for object in vector, which id_number is the same as parameter passed to function*/
{
    auto it = Cars.begin();
    for (it; it < Cars.end(); it++)
    {
        Car* ptr;
        ptr = *it;
        if (ptr->get_id() == car_id) return ptr;
    }
    return nullptr;
}

void Rental::deleteCar(string id)         /*This function is used to delete a car chosen by user*/
{
    int position = -1;
    for (int i = 0; i < Cars.size(); i++) if (Cars[i]->get_id() == id)
    {
        cout << Cars[i]->get_id() << " " << id << endl;
        position = i;
        break;
    }
    if (position == -1)
    {
        cout << "The car with that id does not exist, try again." << endl;
        return;
    }
    Cars.erase(Cars.begin() + position);
}




