#include <iostream>
#include<string>

// #include <string.h>
using namespace std;
// PART 01.0
// Flight class
class Flight
{
private:

int Flight_ID;
int capacity;

double ticket_price;

string Model;
string Airline;
string destination;
string departure_time;

public:

// constructor & destractor

    // Default constructor
    Flight() : Flight_ID(0), capacity(0), ticket_price(0.0), Model(""), Airline(""), destination(""), departure_time("")
    { }
    Flight(int f_id, int capa, double tick_price, string mod, string airli, string desti, string depa_time)
    {
        Flight_ID=f_id;
        capacity =capa;

        ticket_price =tick_price;

        Model =mod;
        Airline =airli;
        destination =desti;
        departure_time =depa_time;

    }

    ~Flight() {}

// setters 
    //int

void Set_ID (int id)
{
    Flight_ID = id;
}
void Set_Capacity (int cpa)
{
    capacity =cpa;
}

    //double

void Set_Price (double price)
{
    ticket_price = price;
}

    //string

void Set_Model (string mdl)
{
    Model =mdl;
}
void Set_Airline (string ali)
{
    Airline =ali;
}
void Set_Destination (string des)
{
    destination =des;
}
void Set_Departure_Time (string dptm)
{
    departure_time =dptm;
}

// getter
    //int
int Get_ID() const
{
    return Flight_ID;
}
int Get_Capacity() const
{
    return capacity;
}

    //double

double Get_Price() const
{
    return ticket_price;
}

    //string

string Get_Model() const
{
    return Model;
}
string Get_Airline() const
{
    return Airline;
}
string Get_Destination() const
{
    return destination;
}
string Get_Departure_Time() const
{
    return departure_time;
}

//Display function

void display_Flight_info(){
    cout<<"Flight ID : " <<Get_ID()<<endl;
    cout<<"Capacity : " <<Get_Capacity()<<endl;

    cout<<"The price: " <<Get_Price()<<endl;

    cout<<"Model : " <<Get_Model()<<endl;
    cout<<"Airline : " <<Get_Airline()<<endl;
    cout<<"Destination : " <<Get_Destination()<<endl;
    cout<<"Departure Time : " <<Get_Departure_Time()<<endl;
}


//! all this part is for solving the errors but i don't understand anything from it ((uderstand that they are operator overloading))
    bool operator!=(const Flight& other) const {
        // Customize the logic for inequality comparison
        // You may choose to compare based on certain criteria, e.g., Flight_ID
        return Flight_ID != other.Flight_ID;}

 bool operator==(const Flight& other) const {
        // Customize the logic for equality comparison
        // You may choose to compare based on certain criteria, e.g., Flight_ID
        return Flight_ID == other.Flight_ID;
    }
    };


// TODO: I have changed the get functions to const and also i don't know why i did that ( GPT :( )
ostream& operator<<(ostream& os, const Flight& flight) {
    os << "Flight ID: " << flight.Get_ID() << "\n"
       << "Capacity: " << flight.Get_Capacity() << "\n"
       << "Price: " << flight.Get_Price() << "\n"
       << "Model: " << flight.Get_Model() << "\n"
       << "Airline: " << flight.Get_Airline() << "\n"
       << "Destination: " << flight.Get_Destination() << "\n"
       << "Departure Time: " << flight.Get_Departure_Time() << "\n";

    return os;
}
//!


//part 02.1

template <class generic_class>
class Node
{
private:

generic_class data;
Node<generic_class> *next;
public:

// setter

void Set_data(generic_class dataa)
{
    data=dataa;
}

void Set_next(Node<generic_class>* next_ptr)
{
    next=next_ptr;
}

//Getter

generic_class Get_data()
{
    return data;
}

Node<generic_class> * Get_next()
{
    return next;
}
Node(generic_class data_cons) : data(data_cons), next(NULL)
{}

    ~Node(){}

};

//part 02.2 

template <class generic_class>

class FlightList
{
private:

Node<generic_class> * head;

public:

//conc

FlightList()
{
    head= NULL;
}

// Four required functions:

//1
//note that addflight function is a function that is used to put a node at the end of the list.

void AddFlight(generic_class datae)
{
//! I didn't know why he write new Node<generic_class>() instead of new Node()
Node<generic_class>* newnode = new Node<generic_class>(datae);
if (head == NULL)
{
cout <<"sir; The list is empty; so we have made to you new one.";
head=newnode;
}

else
{
Node<generic_class>* traverse=head;

//كده هو هيشاور علي اخر نوود و يقف عليها
while (traverse->Get_next()!=NULL)
{
    traverse=traverse->Get_next();
}

newnode->Set_next(NULL);
traverse->Set_next(newnode);


}

}

//2

void Delflight(int flight_ID)
{
if (head==NULL)
{
    cout<<"the list is empty";
}

else{
Node<generic_class>* temp = head;
Node<generic_class>* temp_pre = NULL;

// 3la4an ndor 3la al data
while (temp != NULL && temp->Get_data().Get_ID()!=flight_ID)
{   
    temp_pre=temp;
    temp=temp->Get_next();
}

if (temp==NULL)
{
cout<<"Hey you, enter a right ID or I will kill you";
}

else
{

if (temp_pre == NULL)
{
    head = temp->Get_next();
}
else
{
temp_pre->Set_next(temp->Get_next());

}
delete temp;
temp=NULL;
}
}
}

//3

void DisplayALL()
{

Node<generic_class>* traverse=head;

//كده هو هيشاور علي اخر نوود و يقف عليها
while (traverse!=NULL)
{
    cout<<traverse->Get_data();
    traverse=traverse->Get_next();
}

}

//4
//insert by position 

void Insert_new_flight_by_position(int position,generic_class datae)
{
    Node<generic_class>* newnode = new Node<generic_class>(datae);
    Node<generic_class> *temp = head;

if(head==NULL)
{
cout<<"the list is empty";
head=newnode;
}
else
{
    Node<generic_class>* traverse=head;
    Node<generic_class>* temp_pre=head;

int counter=0;

while (traverse!=NULL)
{
    traverse=traverse->Get_next();
    counter++;
}
if (counter>=position)
{
//3la4an awsl llmkan almtlob
while (--position)
{
    temp_pre=temp;
   temp= temp->Get_next();
}
newnode->Set_next(temp);
temp_pre->Set_next(newnode);

}
else 
{
    cout<<"out of range";
}
}
}

//insert by data

void Insert_new_flight_by_data(generic_class dataa, generic_class pre_dataa)
{
    Node<generic_class>* newnode = new Node<generic_class>(dataa);

    if (head == nullptr)
    {
        head = newnode;
        cout << "The list was empty but I have added the node, sir" << endl;
    }
    else
    {
        Node<generic_class>* temp = head;
        Node<generic_class>* traverse = head;

        // Find the node with pre_dataa
        while (traverse != NULL && traverse->Get_data() != pre_dataa)
        {
            temp = traverse;
            traverse = traverse->Get_next();
        }

        if (traverse == NULL)
        {
            // pre_dataa not found in the list
            cout << "Error: The node with pre_dataa not found in the list." << endl;
            delete newnode;  // Cleanup the dynamically allocated memory
            return;
        }
        // Insert the new node
        newnode->Set_next(traverse->Get_next());
        traverse->Set_next(newnode);

    }
}

};

//part 03.0

//stack using linked-list
template <class generic_class>

class FlightStack
{
private:
    Node<generic_class>* Top;
    Flight item;

public:
FlightStack()
    {
        Top=NULL;
    }

void PushFlight(generic_class x)
    {               
     Node<generic_class> *newNode = new Node<generic_class>(x);

        if (Top==NULL)
            {
                cout<<"The stack was empty sir but i add the new one";
                newNode->Set_data(x);
                newNode->Set_next(NULL);
                Top=newNode;
            }
        else
        {
            bool flag=false;
            Node<generic_class> *temp=Top;

            while (temp->Get_next() != NULL)
            {
                if (temp->Get_data()==x)
                {
                    cout<<"The flight is already in the stack."<<endl;
                    flag=true;
                }                
                temp=temp->Get_next();

            }
            if (!flag)
            {
                newNode->Set_data(x);
                newNode->Set_next(Top);
                Top=newNode;
                cout<<"we have added the stack sir"<<endl;
            }
        }

}

void PrintStack()
{
    Node<generic_class> *temp;
   temp=Top;
   if (Top == NULL)
   {
    cout << "The Stack is Empty!" << endl;
   }
   else
   {
    cout<<"The Flights are : "<<endl;
    while (temp != NULL)
    {
        cout << temp->Get_data() << "  ";
        temp = temp->Get_next() ;
    }
    cout<<endl;
    }

   }

bool IsEmpty() 
{
    return (Top == NULL) ? true : false;
}

void peek()
{
 if (IsEmpty())
 {
    cout<<"the list is empty";
 }
 else
 {
    cout<< Top->Get_data();
 }
}

void edit(generic_class what_do_you_want, generic_class old_data)
{
    if (Top==NULL)
    {
        cout<<"the list is empty";
    }
else
{
Node<generic_class> *temp=Top;

    while (temp != NULL && temp->Get_data() != old_data)
    {
        temp=temp->Get_next();
    }

    if (temp != NULL)
    {
   generic_class datah=temp->Get_data();

    cout<<"we have removed this data"<<endl<<datah<<endl;
    temp->Set_data(what_do_you_want);
    cout<<"this new data have been added"<<endl;
    cout<<what_do_you_want<<endl;
    }
    else
    {
        cout << "Flight with specified data not found in the stack." << endl;
    }

}
}

void deletefun()
{
    if (!IsEmpty())
    {
        Node<generic_class>* temp=Top;
        Top=Top->Get_next();
        delete temp;
    }
    else
    {
        cout<<"The list is empty";
    }
}

};

int main()
{
    cout <<"welcome,sir"<<endl<<"choose option"<<endl<<"1-linkedlist"<<endl<<"2-stack"<<endl;
    int the_choice;
    cin>>the_choice;
    string continuee;        
    FlightList <Flight> Flight_list;
    FlightStack <Flight> Flight_Stack;

    while (continuee!="yes")
{
    if(the_choice==1)
    {
    cout<<"choose the operation,sir"<<endl;

    int the_number_of_operation;
    cout<<"1)Insert new flight"<<endl;
    cout<<"2)Delete Flight"<<endl;
    cout<<"3)Display All Flights"<<endl;
    cout<<"4)close the program"<<endl;
    cin>>the_number_of_operation;

    switch (the_number_of_operation)
    {
    case 1:
        {
        cout<<"sir, now i want from you the data"<<endl;

        int flightid;
        int capa;

        cout<<"what is the flight id?"<<endl;
        cin>>flightid;
        cout<<"what is the capacity of the airplane?"<<endl;
        cin>>capa;

        double tickp;

        cout<<"what is the price for each ticket"<<endl;
        cin>>tickp;

        string modd;
        string airlnee;
        string dest;
        string depaa;

        cout<<"could you write the airplane model?"<<endl;
        cin>>modd;
        cout<<"could you write the airline name"<<endl;
        cin>>airlnee;
        cout<<"could you mention the destination"<<endl;
        cin>>dest;
        cout<<"could you tell me the depature time"<<endl;
        cin>>depaa;
        
        Flight new_dataa(flightid,capa,tickp,modd,airlnee,dest,depaa);
        
        cout<<"sir, do you want to insert by 1)data \n 2)position \n 3) at the end of the list"<<endl;
        int the_answer;
        cin>>the_answer;

        if (the_answer==1)
        {
        cout<<"sir, now i want from you the data that you wnat to insert after it the new node"<<endl;

        int flightid_old;
        int capa_old;

        cout<<"what is the flight id?"<<endl;
        cin>>flightid_old;
        cout<<"what is the capacity of the airplane?"<<endl;
        cin>>capa_old;

        double tickp_old;

        cout<<"what is the price for each ticket"<<endl;
        cin>>tickp_old;

        string modd_old;
        string airlnee_old;
        string dest_old;
        string depaa_old;

        cout<<"could you write the airplane model?"<<endl;
        cin>>modd_old;
        cout<<"could you write the airline name"<<endl;
        cin>>airlnee_old;
        cout<<"could you mention the destination"<<endl;
        cin>>dest_old;
        cout<<"could you tell me the depature time"<<endl;
        cin>>depaa_old;
        
        Flight old_dataa(flightid_old,capa_old,tickp_old,modd_old,airlnee_old,dest_old,depaa_old);

        Flight_list.Insert_new_flight_by_data(new_dataa,old_dataa);
        }
        else if (the_answer==2)
        {
            cout<<"sir, now i want from you the position where you want to insert the new node"<<endl;
            int posiiton;
            cin>>posiiton;
            Flight_list.Insert_new_flight_by_position(posiiton,new_dataa);
        }
        else if (the_answer==3)
        {
            Flight_list.AddFlight(new_dataa);
        }
           break;

    }

    case 2:
    {
        int the_ID;
        cout <<"sir could you write the flight ID";
        cin>>the_ID;
        Flight_list.Delflight(the_ID);
        break;
    }
    case 3:
    {
        Flight_list.DisplayALL();
        break;
    }
    case 4:
    cout<<"closed";
    continuee="yes";
    break;

    default:
    cout << "Invalid choice!" << endl;
        break;
    }

    }
else if (the_choice==2)
{
    cout<<"choose the operation"<<endl;

    int the_number_of_operation;
    cout<<"1) Insert new flight"<<endl;
    cout<<"2) Check the lastest added flight"<<endl;
    cout<<"3) Print all the flights "<<endl;
    cout<<"4) Edit flight"<<endl;
    cout<<"5) Delete a flight"<<endl;
    cout<<"6) Close the program"<<endl;
    cin >> the_number_of_operation ;

    switch (the_number_of_operation)
    {
    case 1:
    {
        cout<<"could you give me the flight infomrmation,sir"<<endl;

        int flightid;
        int capa;

        cout<<"what is the flight id?"<<endl;
        cin>>flightid;
        cout<<"what is the capacity of the airplane?"<<endl;
        cin>>capa;

        double tickp;

        cout<<"what is the price for each ticket"<<endl;
        cin>>tickp;

        string modd;
        string airlnee;
        string dest;
        string depaa;

        cout<<"could you write the airplane model?"<<endl;
        cin>>modd;
        cout<<"could you write the airline name"<<endl;
        cin>>airlnee;
        cout<<"could you mention the destination"<<endl;
        cin>>dest;
        cout<<"could you tell me the depature time"<<endl;
        cin>>depaa;
        
        Flight new_dataa(flightid,capa,tickp,modd,airlnee,dest,depaa);

        Flight_Stack.PushFlight(new_dataa);

        break;
    }
    case 2:
    {
        cout << "lastest added flight:" << endl;
        Flight_Stack.peek();
        break;
    }
    case 3:
    {
        cout<<"This is all flights list"<<endl;
        Flight_Stack.PrintStack();
        break;
    }
    case 4:
    {
        int flightid;
        int capa;

        cout<<"what is the flight id?"<<endl;
        cin>>flightid;
        cout<<"what is the capacity of the airplane?"<<endl;
        cin>>capa;

        double tickp;

        cout<<"what is the price for each ticket"<<endl;
        cin>>tickp;

        string modd;
        string airlnee;
        string dest;
        string depaa;

        cout<<"could you write the airplane model?"<<endl;
        cin>>modd;
        cout<<"could you write the airline name"<<endl;
        cin>>airlnee;
        cout<<"could you mention the destination"<<endl;
        cin>>dest;
        cout<<"could you tell me the depature time"<<endl;
        cin>>depaa;
        
        Flight new_dataa(flightid,capa,tickp,modd,airlnee,dest,depaa);

            cout<<"sir, now i want from you the data that you want to modify on it "<<endl;

        int flightid_old;
        int capa_old;

        cout<<"what is the flight id?"<<endl;
        cin>>flightid_old;
        cout<<"what is the capacity of the airplane?"<<endl;
        cin>>capa_old;

        double tickp_old;

        cout<<"what is the price for each ticket"<<endl;
        cin>>tickp_old;

        string modd_old;
        string airlnee_old;
        string dest_old;
        string depaa_old;

        cout<<"could you write the airplane model?"<<endl;
        cin>>modd_old;
        cout<<"could you write the airline name"<<endl;
        cin>>airlnee_old;
        cout<<"could you mention the destination"<<endl;
        cin>>dest_old;
        cout<<"could you tell me the depature time"<<endl;
        cin>>depaa_old;
        
        Flight old_dataa(flightid_old,capa_old,tickp_old,modd_old,airlnee_old,dest_old,depaa_old);

        Flight_Stack.edit(new_dataa,old_dataa);
        break;
    }
    case 5:
    {
        Flight_Stack.deletefun();
        break;
    }
    case 6:
    {
        cout<<"the program is closed :)";
        continuee="yes";
        break;
    }
    default:
    cout<<"Invalid choice!";
    break;
    }
    }
    int x;
    cout << "enter x : "<<endl;
    cin >> x;
    if (x==0)
    continuee="yes";
    

}
}