#include <iostream>
#include <string>
using namespace std;

class Flight {
    private :
    int Flight_ID;
    string Model;
    int  Capacity;
    string Airline;
    string Destination;
    string Departure_Time;
    double Ticket_Price;
    public :
    // prametrize constractor 
    Flight(int id,string mod,int cap,string airl,string dest,string time,double price)
    {
        Flight_ID = id;
        Model = mod;
        Capacity = cap;
        Airline=airl;
        Destination = dest;
        Departure_Time = time ;
        Ticket_Price = price ;

    }   
    // setter 
    void set_Flight_ID (int F_id)
    {
        Flight_ID = F_id; 
    }
    void set_Model (string F_model)
    {
        Model =F_model; 
    }
    void set_Capacity (int F_cap)
    {
        Capacity = F_cap; 
    }
    void set_Airline (string F_Airline)
    {
        Airline =F_Airline; 
    }
    void set_Destination (string F_Destination)
    {
        Destination =F_Destination; 
    }
    void set_Departure_Time (string F_Departure_Time)
    {
        Departure_Time =F_Departure_Time; 
    }
    void set_T_price(double T_price)
    {
        Ticket_Price = T_price;
    }
    // getter 
    int get_Flight_ID ()
    {
        return Flight_ID;
    }
    string get_Model ()
    {
        return Model;
    }
    int get_Capacity ()
    {
        return Capacity;
    }
    string get_Airline ()
    {
        return Airline;
    }
    string get_Destination ()
    {
        return Destination;
    }
    string get_Departure_Time ()
    {
        return Departure_Time;
    }
    double get_Ticket_Price()
    {
        return Ticket_Price;
    }
    // display method 
    void  display_Flight_info()
    {
        cout << "Flight Id : " <<get_Flight_ID() <<endl;
        cout << "Flight Model : " <<get_Model() <<endl;
        cout << "Flight Capicity : "<<get_Capacity() <<endl;
        cout << "Flight Airline : "<<get_Airline() <<endl;
        cout << "Flight Destination : "<<get_Destination() <<endl;
        cout << "Flight Departure Time : "<<get_Departure_Time() <<endl;
        cout << "Flight Ticket Price : "<<get_Ticket_Price() <<endl;
    }  

};

int main ()
{
    int FL_Id,FL_Cap;
    string FL_Model,FL_Airline,FL_distniation,FL_Departure_Time;
    double FL_Ticket_Price;
    cout << "Enter the Flight id : \n";
    cin >> FL_Id;
    cout << "Enter the Flight model : \n";
    cin >> FL_Model;
    cout << "Enter the Flight capicity : \n";
    cin >> FL_Cap;
    cout << "Enter the Flight Airline : \n";
    cin >> FL_Airline;
    cout << "Enter the Flight distnation : \n";
    cin >> FL_distniation;
    cout << "Enter the Flight departure time : \n";
    cin >> FL_Departure_Time;
    cout << "Enter the Flight ticket price : \n";
    cin >> FL_Ticket_Price;

    Flight F1(FL_Id,FL_Model,FL_Cap,FL_Airline,FL_distniation,FL_Departure_Time,FL_Ticket_Price);
    F1.display_Flight_info();
}