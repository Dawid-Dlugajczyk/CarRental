#include "List.h"
#include "Rental.h"

Rent::Rent()
{
    next = 0;
}

list::list()
{
    First = 0;
}

void list::new_Rent(string car_id, string user_id)                      /*This function is used to add new element to the list*/
{
    Rental r;
    Rent* nowa = new Rent;  

   
    nowa ->car_id = car_id;
    nowa ->user_id = user_id;
 

    if (First == 0) 
    {
        First = nowa;
    }
    else
    {
        Rent* temp = First;

        while (temp->next)
        {

            temp = temp->next;
        }

        temp->next = nowa;
        nowa->next = 0;    
    }
}


void list::ShowList()                                    /*This function prints list with rentions*/
{
    Rent* temp = First;
    int counter;
    counter = 1;
    

    while (temp)
    {
        
        cout << endl <<  counter << "." << endl;
        cout << "Vehicle with id number: " << temp-> car_id << "\nUser with id number: " << temp->user_id << endl;
        cout << "\n ----------------------" << endl;
        temp = temp->next;
        counter++;
    }
}

void list::delete_Rent(int nr)          /*This function deletes chosen element from the list */
{

    if (nr == 1)
    {
        Rent *temp = First;
        First = temp->next;
        delete temp; 
    }
    else if (nr >= 2)
    {
        int j = 1;


        Rent *temp = First;
       

        while (temp)
        {

            if ((j + 1) == nr) break;


            temp = temp->next;
            j++;
        }

        if (temp->next->next == 0)
        {
            delete temp->next;
            temp->next = 0;
        }
        else {
            Rent *deleted = temp->next;
            temp->next = temp->next->next;
            delete deleted;
        }
    }
    cout << "Car returned." << endl;
}

void list::WriteFile()
{
    ofstream ren;
    Rent* temp = First;

    
    

    ren.open("Rent.txt", ios::out);
    if (ren.is_open())
    {
        while (temp)
        {
            ren << temp->car_id << " " << temp->user_id << endl;
            temp = temp->next;
        }
    }
    else cout << "Error" << endl;
    ren.close();
}

void list::ReadFile()
{
    ifstream rent;
    string car_id,user_id, s;
    rent.open("Rent.txt", ios::in);
    if (rent.is_open())
    {

        string var;
        while (rent >> var)
        {
            car_id = var;
            rent >> var;
            user_id = var;
            
            new_Rent(car_id, user_id);
        }
    }
      else cout << "File was not open" << endl;

}
