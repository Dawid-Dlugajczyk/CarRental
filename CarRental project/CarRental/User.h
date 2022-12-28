#pragma once
#include <iostream>
#include <vector>

using namespace std;

class User
{
   // vector<User*> Users;
private:
    string name;
    string surname;
    string id_number;
    string pesel;

public:
    User() = default;
    User(string name, string surname, string id_number, string pesel);
    User(string s);
    ~User();
    friend ostream& operator<<(ostream& os, const User& u);
    string get_id()
    {
        return this->id_number;
    };

    string get_surname()
    {
        return this->surname;
    }
    string get_name()
    {
        return this->name;
    }
    string get_pesel()
    {
        return this->pesel;
    }
    

   /* vector<User*>& getList()
    {
        return Users;
    }*/
};