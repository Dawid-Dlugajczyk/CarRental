#include "User.h"
#include<string>
#include<vector>

using namespace std;

User::User(string name, string surname, string id_number, string pesel)          /*This constructor is used while the new user is added to list*/
{
    this->name = name;
    this->surname = surname;
    this->id_number = id_number;
    this->pesel = pesel;
}



User::User(string s)          /*This constructor takes string from the file, it "cuts" them and assign to proper variables*/
{
    vector<int> vec;
    for (int i = 0; i < s.size(); i++) if (s[i] == ' ') vec.push_back(i);
    name = s.substr(0, vec[0]);
    surname = s.substr(vec[0] + 1, vec[1] - 1 - (vec[0]));
    id_number = s.substr(vec[1] + 1, vec[2] - 1 - vec[1]);
    pesel = s.substr(vec[2] + 1, s.size() - 1);
}



