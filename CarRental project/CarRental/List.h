#pragma once
#include "Rental.h"
#include <string>

struct Rent {
    string car_id;
    string user_id;
    Rent* next;
    Rent();
};


struct list {  
  Rent* First;

    void new_Rent(string car_id, string user_id);
    void delete_Rent(int n);
    void ShowList();
    void WriteFile();
    void ReadFile();

    list();
};

