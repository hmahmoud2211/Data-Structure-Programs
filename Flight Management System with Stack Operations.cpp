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

// tamplete class to put any data type in the node 
template <typename T>
// class Node
class Node{
    // 2 attributes
    public:
        T data;
        Node<T>* next;
        // constructor
        Node(T e)
        {
            data = e;
            next = NULL;
        }
};

template <class S>
class Flightstack{
private:
Node<S>* Top;

public:
    // Constructor to initialize the stack
    FlightStack()
    {
        Top = nullptr;
    }
    
    bool IsDuplicate(S fData) {
        Node<S>* current = Top;
        while (current != nullptr) {
            if (current->data == fData) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool IsEmpty() {
        return Top == nullptr;
    }

    // Method to add flight to the stack (reject duplicates)
    void PushFlight(S flightData) {
        // Check for duplicates
        if (IsDuplicate(flightData)) 
        {
            cout << "this flight data is repeted"<<endl;
        }
        else 
        {
            Node<S>* Node1 = new Node<S>(flightData);
            Node1->next = Top;
            Top = Node1;
        }
    }
    void PrintStack() {
        Node<S>* current = Top;
        cout << "Flights in LIFO order : "<<endl;
        while (current != nullptr) {
            cout << current->data <<endl;
            current = current->next;
        }
    }
    S Peek() {
        if (IsEmpty()) 
        {
            cout << "the stack is empty"<<endl;
        }
        else 
        {
            return Top->data;
        }
        
    }
    void EditOrDeleteFlight(S oldFlightData, S newFlightData) {
        if (IsEmpty()) {
            cout << "Stack is empty. Cannot edit or delete."<<endl;
            
        }
        else 
        {
        Node<S>* current = Top;
        Node<S>* prev = nullptr;

        while (current != nullptr && current->data != oldFlightData) 
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            current->data = newFlightData;
        } 
        else 
        {
            cout << "This Flight is Not Found."<<endl;
        }

        }

        
    }
};