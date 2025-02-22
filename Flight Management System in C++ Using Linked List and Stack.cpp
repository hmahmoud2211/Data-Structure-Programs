#include <iostream>
#include <string>
#include <cstdlib>

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
    int get_Flight_ID () const
    {
        return Flight_ID; 
    }
    string get_Model ()const
    {
        return Model;
    }
    int get_Capacity ()const
    {
        return Capacity;
    }
    string get_Airline ()const
    {
        return Airline;
    }
    string get_Destination ()const
    {
        return Destination;
    }
    string get_Departure_Time () const
    {
        return Departure_Time;
    }
    double get_Ticket_Price()const
    {
        return Ticket_Price;
    }
    // display method 
    void  display_Flight_info()const
    {
        cout << "Flight Id : " <<get_Flight_ID() <<endl;
        cout << "Flight Model : " <<get_Model() <<endl;
        cout << "Flight Capicity : "<<get_Capacity() <<endl;
        cout << "Flight Airline : "<<get_Airline() <<endl;
        cout << "Flight Destination : "<<get_Destination() <<endl;
        cout << "Flight Departure Time : "<<get_Departure_Time() <<endl;
        cout << "Flight Ticket Price : "<<get_Ticket_Price() <<endl;
    }  
    bool operator == (const Flight& other) const {
        return (
            Flight_ID == other.Flight_ID &&
            Model == other.Model &&
            Capacity == other.Capacity &&
            Airline == other.Airline &&
            Destination == other.Destination &&
            Departure_Time == other.Departure_Time &&
            Ticket_Price == other.Ticket_Price
        );
    }
    bool operator != (const Flight& other) const {
        return (
            Flight_ID != other.Flight_ID &&
            Model != other.Model &&
            Capacity != other.Capacity &&
            Airline != other.Airline &&
            Destination != other.Destination &&
            Departure_Time != other.Departure_Time &&
            Ticket_Price != other.Ticket_Price
        );
    }


};

// tamplete class to put any data type in the node 
template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    // constructor
    Node(T e) : data(e), next(nullptr) {}
};


// tamplete class to put any data type in the node 
template <class T>
// class flight list 
class FlightList {
    private:
    // create the head
	Node<T>* head;

    public:
        // constructor 
    	FlightList()
        {
    	    head= NULL;
    	}
        // add flight method
        void AddFlight(T data) {
            // create new node 
        Node<T>* node_1 = new Node<T>(data);
        // check the code is empty or not 
        if (head == NULL) 
        {
            head = node_1;
        } 
        // add the new node to list 
        else {
            Node<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node_1;
        }
    }

    // delete flight method 
    void DelFlight(int id) {
    Node<T>* temp = head;
    Node<T>* prev = NULL;

    // Check if the list is empty
    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    // Check if the data of the first node matches the id to delete
    if (head->data.get_Flight_ID() == id) {
        head = temp->next;
        delete temp;
        return;
    }

    // Traverse the list to find the node with the specified id
    while (temp != NULL && temp->data.get_Flight_ID() != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the id is not found in the list
    if (temp == NULL) {
        cout << "Flight with ID " << id << " not found\n";
        return;
    }

    // Update the next pointer of the previous node to skip the node to be deleted
    prev->next = temp->next;

    // Delete the node
    delete temp;
}

    // display method 
    void DisplayAll() {
        // make temp pointer
        Node<T>* temp = head;
        // display the list by traversing
        while (temp != NULL) {
            temp->data.display_Flight_info();
            temp = temp->next;
        }
        cout << "the end of the node !"<<endl;
        cout << "\n";
    }
};

template <class T>
class FlightStack {
private:
Node<T>* Top;

public:

    // Constructor to initialize the stack
    FlightStack()
    {
        Top = nullptr;
    }

    bool IsDuplicate(T fData) {
        Node<T>* current = Top;
        while (current != nullptr) {
            if (current->data == fData) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool IsEmpty() {
        return (Top == nullptr);
    }

    // Method to add flight to the stack (reject duplicates)
    void PushFlight(T flightData) {
         Node<T>* Node1 = new Node<T>(flightData);
        if (IsEmpty()){
            Top = Node1;
            return; 
        }
        // Check for duplicates
        if (IsDuplicate(flightData)) 
        {
            cout << "this flight data is repeted"<<endl;
        }
        else 
        {
           
            Node1->next = Top;
            Top = Node1;
        }
    }
    void PrintStack() {
        Node<T>* current = Top;
        cout << "Flights in LIFO order : "<<endl;
        while (current!= NULL){
             current->data.display_Flight_info();
             current = current->next;

        }
      
    }
    T Peek() {
        if (IsEmpty()) 
        {
            cout << "the stack is empty"<<endl;
        }
        else 
        {
            return Top->data;
        }
        
    }
    void EditOrDeleteFlight(T oldFlightData, T newFlightData) {
        if (IsEmpty()) {
            cout << "Stack is empty. Cannot edit or delete."<<endl;
            return;   
        }
        else 
        {
        Node<T>* current = Top;


        while (current != nullptr && current->data != oldFlightData) 
        {
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
    void PopFlight() {
        if (IsEmpty()) {
            cout << "Stack is empty. Cannot delete." << endl;
            return;
        }

        Node<T>* temp = Top;
        Top = Top->next;
        delete temp;
    }
};

int main() {
    FlightList <Flight> flightList;
    FlightStack <Flight> flightStack;

    int choice;

    do {
        cout << "Welcome to the Flight Management System!" << endl;
        cout << "Menu Options:" << endl;
        cout << "1. LinkedList" << endl;
        cout << "2. Stack" << endl;
        cout << "Enter your choice (1-2): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "LinkedList Options:" << endl;
                cout << "1. Insert new flight" << endl;
                cout << "2. Delete Flight" << endl;
                cout << "3. Display All Flights" << endl;
                cout << "4. Close the program" << endl;

                int linkedListChoice;
                cout << "Enter your choice (1-4): ";
                cin >> linkedListChoice;

                switch (linkedListChoice) {
                    case 1: {
                        // Insert new flight
                        int FL_Id, FL_Cap;
                        string FL_Model, FL_Airline, FL_distniation, FL_Departure_Time;
                        double FL_Ticket_Price;

                        cout << "Enter the Flight id: ";
                        cin >> FL_Id;
                        cout << "Enter the Flight model: ";
                        cin >> FL_Model;
                        cout << "Enter the Flight capicity: ";
                        cin >> FL_Cap;
                        cout << "Enter the Flight Airline: ";
                        cin >> FL_Airline;
                        cout << "Enter the Flight distnation: ";
                        cin >> FL_distniation;
                        cout << "Enter the Flight departure time: ";
                        cin >> FL_Departure_Time;
                        cout << "Enter the Flight ticket price: ";
                        cin >> FL_Ticket_Price;

                        Flight newFlight(FL_Id, FL_Model, FL_Cap, FL_Airline, FL_distniation, FL_Departure_Time, FL_Ticket_Price);
                        flightList.AddFlight(newFlight);
                        break;
                    }
                    case 2: {
                        // Delete Flight
                        int flightIdToDelete;
                        cout << "Enter the Flight ID to delete: ";
                        cin >> flightIdToDelete;
                        flightList.DelFlight(flightIdToDelete);
                        break;
                    }
                    case 3:
                        flightList.DisplayAll();
                        break;
                    case 4:
                        cout << "Closing the program." << endl;
                        exit(0);
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;

            case 2:
                cout << "Stack Options:" << endl;
                cout << "1. Insert new flight" << endl;
                cout << "2. Check the latest Added Flight" << endl;
                cout << "3. Print all the flights" << endl;
                cout << "4. Edit flight" << endl;
                cout << "5. Delete flight" << endl;
                cout << "6. Close the program" << endl;

                int stackChoice;
                cout << "Enter your choice (1-6): ";
                cin >> stackChoice;

                switch (stackChoice) {
                    case 1: {
                        // Insert new flight
                        int FL_Id, FL_Cap;
                        string FL_Model, FL_Airline, FL_distniation, FL_Departure_Time;
                        double FL_Ticket_Price;

                        cout << "Enter the Flight id: ";
                        cin >> FL_Id;
                        cout << "Enter the Flight model: ";
                        cin >> FL_Model;
                        cout << "Enter the Flight capicity: ";
                        cin >> FL_Cap;
                        cout << "Enter the Flight Airline: ";
                        cin >> FL_Airline;
                        cout << "Enter the Flight distnation: ";
                        cin >> FL_distniation;
                        cout << "Enter the Flight departure time: ";
                        cin >> FL_Departure_Time;
                        cout << "Enter the Flight ticket price: ";
                        cin >> FL_Ticket_Price;

                        Flight newFlight(FL_Id, FL_Model, FL_Cap, FL_Airline, FL_distniation, FL_Departure_Time, FL_Ticket_Price);
                        flightStack.PushFlight(newFlight);
                        break;
                    }
                    case 2:
                        // Check the latest Added Flight
                        cout << "Latest Added Flight: ";
                        flightStack.Peek().display_Flight_info();
                        break;
                    case 3:
                        // Print all the flights
                        flightStack.PrintStack();
                        break;
                    case 4: {
                        // Edit flight
                        int oldFlightId, newFlightId;
                        cout << "Enter the old Flight ID: ";
                        cin >> oldFlightId;
                        cout << "Enter the new Flight ID: ";
                        cin >> newFlightId;

                        Flight newFlight = flightStack.Peek();
                        newFlight.set_Flight_ID(newFlightId);

                        flightStack.EditOrDeleteFlight(flightStack.Peek(), newFlight);
                        break;
                    }
                    case 5: {
                        // Delete flight
                        flightStack.PopFlight();
                        cout << "Latest Added Flight deleted." << endl;
                        break;
                    }
                    case 6:
                        cout << "Closing the program." << endl;
                        exit(0);
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Do you want to choose another option? (1 for Yes, 0 for No): ";
        cin >> choice;

    } while (choice != 0);

    return 0;
}
