#include <iostream>

using namespace std;
// the Flight class to represent flight information
   class flight{
private:
    int flight_id;
    string model;
    int capacity;
    string airline;
    string destination;
    string departure_time;
    double ticket_price;

public:
    //constructor for flight class
       flight(int fid ,string m ,int c ,string al ,string d ,string dt ,double tp){

       flight_id=fid;
       model=m;
       capacity=c;
       airline=al;
       destination=d;
       departure_time=dt;
       ticket_price=tp;



       }

       //setters
    void set_flight_id(int fid){
    flight_id=fid;
    }

       void set_model(string m){
    model=m;
    }
        void set_capacity(int c){
    capacity=c;
    }

        void set_airline(string al){
    airline=al;
    }

        void set_destination(string d){
    destination=d;
    }

        void set_departure_time(string dt){
    departure_time=dt;
    }

        void set_ticket_price(double tp){
    ticket_price=tp;
    }

    //getters
        int get_flight_id(){
       return flight_id;
    }

       string get_model(){
       return model;
    }
        int get_capacity(){
    return capacity;
    }

       string get_airline(){
    return airline;
    }

        string get_destination(){
    return destination;
    }

        string get_departure_time(){
    return departure_time;
    }

        double get_ticket_price(){
    return ticket_price;
    }

    //function to display flight info
    void display_flight_info(){

    cout<<"flight id:"<<flight_id<<endl;
    cout<<"model:"<<model<<endl;
    cout<<"capacity:"<<capacity<<endl;
    cout<<"airline:"<<airline<<endl;
    cout<<"destination:"<<destination<<endl;
    cout<<"departure time:"<<departure_time<<endl;
    cout<<"ticket price:"<<ticket_price<<endl;

    }

   };


   template <class flight>
   class Node{
    public:
        flight data;
        Node<flight>* next;

       Node(const flight& e) : data(e), next(NULL) {}

};


  template <class flight>
class FlightList{

    public:
        Node<flight>* head;
    	FlightList(){
    	    head= NULL;
    	}

//function to add flight to the end of the list
    	void addflight(flight e){

        Node<flight>* newNode = new Node<flight>(e);



    	if (head==NULL){

        newNode->next=NULL;
         head=newNode;

    	}

    	else{

          Node<flight>* temp=head;
          while(temp->next!=NULL){

            temp=temp->next;
          }

            temp->next=newNode;
           newNode->next=NULL;

    	}


    	}

       //function to delete a node from the linked list
    	void delflight(int flightid){

    	if (head==NULL){

            cout<<"sorry, the list is already empty"<<endl;
    	}

    	else {
        Node<flight>* temp=head;
        Node<flight>* prev=NULL;

        // Check if the flight to be deleted is the head of the list
            if (temp != NULL && temp->data.get_flight_id() == flightid) {
                head = temp->next;
                delete temp;
                cout<<"the flight with id "<<flightid<<" is deleted successfully"<<endl;
                return;
            }

          while(temp!=NULL && temp->data.get_flight_id()!=flightid ) {

            prev=temp;
            temp=temp->next;

          }

            if (temp == NULL) {
            cout << "Flight with ID " << flightid << " not found." << endl;

            }

            prev->next=temp->next;
            delete temp;
    	}
    	}

     //function that display all nodes in linked list
    	void displayall(){
        Node<flight>* temp=head;
        if(head==NULL){
            cout<<"sorry, the list is empty"<<endl;

        }
        else{
        while(temp!=NULL){

         temp->data.display_flight_info();
         temp=temp->next;
        }

        }

    	}


    	void insert_new_flight(int position,flight e){

    	Node<flight>* newNode = new Node<flight>(e);

    	if (position == 0){

            cout<<"sorry , please provide a positive position"<<endl;

    	}

        // If the list is empty and the position is 1
    	if (head==NULL){
            if(position==1){
                head=newNode;
                newNode->next=NULL;
            }
            else{
            cout << "Invalid position. The list is empty." << endl;
            }

    	}

    	        if (position == 1) {
            // If the position is 1, insert at the beginning
            newNode->next = head;
            head = newNode;
            return;
        }

                // Find the position to insert
        Node<flight>* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position. The list is not long enough." << endl;
            return;
        }

        // Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;
    }





};

template<class flight>
class flightstack{

public:
    Node<flight>* top;


    flightstack(){
    top=NULL;
    }
      // a function to know if the stack is empty or not
        bool isempty(){
        if (top==NULL){
            return true;
        }
        else{
            return false;
        }


        }

    void pushflight(flight e){

    Node<flight>* newNode = new Node<flight>(e);

if (isempty()){

    newNode->next=NULL;
    top=newNode;

}
else{
    Node<flight>* temp=top;


    while(temp!=NULL){

    if(temp->data.get_flight_id() == newNode->data.get_flight_id()){
        cout<<"error , this flight already exist"<<endl;
        delete newNode;
     break;
    }
     temp=temp->next;
    }
    newNode->next=top;
    top=newNode;
}

    }


    void printstack(){

    if (isempty()){

    cout<<"sorry , the stack is still empty."<<endl;

}

else{
      Node<flight>* temp=top;
    while(temp!=NULL){

       temp->data.display_flight_info();
        temp=temp->next;
    }
    }
    }

    void peek(){
       if(isempty()){

        cout<<"sorry, the list is empty."<<endl;
       }
    else{

        cout<<"this is the latest added flight to the stack: "<<endl;

        top->data.display_flight_info();

    }


    }

    //function to delete a node from the stack
    void pop(){

    if (top==NULL){

        cout<<"sorry , the stack is already empty"<<endl;

    }


    else{

            Node<flight>* temp=top;

        top=top->next;

        delete temp;
    }
    }

    void edit_stack(int flightid){
         Node<flight>* temp=top;

         if(isempty()){
            cout<<"the flight is still empty"<<endl;
         }

         else{
         while(temp!=NULL && temp->data.get_flight_id()!=flightid ){

            temp=temp->next;
         }

         cout<<"here is the original flight"<<endl;
         temp->data.display_flight_info();

         cout<<"please enter the new information for the flight with id "<<flightid<<":"<<endl;



    string model;
    cout << "Model: ";
    cin >> model;
    temp->data.set_model(model);

    int capacity;
    cout << "Capacity: ";
    cin >> capacity;
    temp->data.set_capacity(capacity);

    string airline;
    cout << "Airline: ";
    cin >> airline;
    temp->data.set_airline(airline);

    string destination;
    cout << "Destination: ";
    cin >> destination;
    temp->data.set_destination(destination);

    string departure_time;
    cout << "Departure Time: ";
    cin >> departure_time;
    temp->data.set_departure_time(departure_time);

    double ticket_price;
    cout << "Ticket Price: ";
    cin >> ticket_price;
    temp->data.set_ticket_price(ticket_price);

    }
     cout<<"the data is updated successfully"<<endl;
    }

};





int main()
{
    //taking object from FlightList and flight stack
    FlightList<flight> flightList;
    flightstack<flight> FlightStack;
   flight flight1(0,"",0,"","","",0.0);

    cout<<"Welcome to the Employee Management System"<<endl;

    while (true){
    cout<<"Choose of the following options to use the system features"<<endl;
    cout << "1. Linked List" << endl;
    cout << "2. Stack" << endl;
    cout << "3. exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin>>choice;


    //that if the user chooses linked list option
    if (choice==1){
        int choice2;
        cout<<"choose the operation you want to perform in the linked list, please"<<endl;
        cout << "1.	add new flight" << endl;
        cout << "2. delete flight" << endl;
        cout << "3. display all flights" << endl;
        cout << "4. close the program" << endl;
        cin>>choice2;

        //if the user chooses to add new flight
        if(choice2==1){


//taking from the user the number of flights he want to add
    cout<<"enter the number of flights you want to add:"<<endl;
    int number_of_flights;
    cin>>number_of_flights;

    //a for loop to add the number of flights the user wants
    for(int i=1 ; i<=number_of_flights ; i++){

    cout << "Enter flight information for Flight "<<i<<":" << endl;

    //here the user enters the flights id
    cout << "Flight ID: ";
    int id;
    cin >> id;
    flight1.set_flight_id(id);

    string model;
    cout << "Model: ";
    cin >> model;
    flight1.set_model(model);

    int capacity;
    cout << "Capacity: ";
    cin >> capacity;
    flight1.set_capacity(capacity);

    string airline;
    cout << "Airline: ";
    cin >> airline;
    flight1.set_airline(airline);

    string destination;
    cout << "Destination: ";
    cin >> destination;
    flight1.set_destination(destination);

    string departure_time;
    cout << "Departure Time: ";
    cin >> departure_time;
    flight1.set_departure_time(departure_time);

    double ticket_price;
    cout << "Ticket Price: ";
    cin >> ticket_price;
    flight1.set_ticket_price(ticket_price);


    cout<<"do you want to insert flight "<<i<<" in a specific position (1=Y/2=N)"<<endl;

    int insertion;
    cin>>insertion;


    //here if user chooses to add flight to the end of the list
    if(insertion==2){
     flightList.addflight(flight1);
       cout << "here are the flights you added :" << endl;
        flightList.displayall();
    }


//here if the user chooses to insert flight in a specific postion
    else if(insertion==1){
        int position;
        cout<<"please enter the position you want to add the flight in"<<endl;
        cin>>position;
        flightList.insert_new_flight(position,flight1);
          cout << "here are the flights you added :" << endl;
        flightList.displayall();
    }

    else{cout<<"please enter a valid position"<<endl;}






}
        }

        //here if the user chooses to delete a flight
    else if (choice2==2){

       int i_d;
       cout<<"please enter the id of the flight you want to delete"<<endl;
       cin>>i_d;
       flightList.delflight(i_d);


    }

    //here if the user chooses to display all flights
    else if (choice2==3){


   flightList.displayall();

    }

    //here if the user chooses to close the program
    else if (choice2==4){

        cout<<"thank you for choosing our program"<<endl;
      break;
    }

    else{
        cout << "Invalid choice. Please enter a valid option." << endl;

    }
    }
   //this is if the user chooses the stack option
    else if (choice==2){
        int choice3;
        cout<<"choose the operation you want to perform in the stack, please."<<endl;
        cout << "1.	Insert new flight" << endl;
        cout << "2. check the latest added flight" << endl;
        cout << "3. print all flights" << endl;
        cout << "4. edit a flight" << endl;
        cout << "5. delete a flight" << endl;
        cout << "6. close the program" << endl;
        cin>>choice3;

     if (choice3==1){



    cout<<"enter the number of flights you want to add:"<<endl;
    int number_of_flights;
    cin>>number_of_flights;

    for(int i=1 ; i<=number_of_flights ; i++){
    cout << "Enter flight information for Flight "<<i<<":" << endl;

    cout << "Flight ID: ";
    int id;
    cin >> id;
    flight1.set_flight_id(id);

    string model;
    cout << "Model: ";
    cin >> model;
    flight1.set_model(model);

    int capacity;
    cout << "Capacity: ";
    cin >> capacity;
    flight1.set_capacity(capacity);

    string airline;
    cout << "Airline: ";
    cin >> airline;
    flight1.set_airline(airline);

    string destination;
    cout << "Destination: ";
    cin >> destination;
    flight1.set_destination(destination);

    string departure_time;
    cout << "Departure Time: ";
    cin >> departure_time;
    flight1.set_departure_time(departure_time);

    double ticket_price;
    cout << "Ticket Price: ";
    cin >> ticket_price;
    flight1.set_ticket_price(ticket_price);


FlightStack.pushflight(flight1);
    }
    cout << "here are the flights you added :" << endl;

FlightStack.printstack();

}

////here if the user chooses to display the latest added flight in stack
   else if (choice3==2){

    FlightStack.peek();


   }

   //here if the user chooses to display all flights in stack
      else if (choice3==3){

    FlightStack.printstack();


   }

//here if the user wants to edit a specific flight
         else if (choice3==4){

     cout<<"please enter the id of the flight to edit: ";
     int flightid;
     cin>>flightid;

    FlightStack.edit_stack(flightid);


   }
//here if the user chooses to delete the latest added flight in stack
            else if (choice3==5){

    FlightStack.pop();


   }

            else if (choice3==6){

    cout<<"Thanks for choosing our program ";
    break;

   }

           else{

            cout << "Invalid choice. Please enter a valid option." << endl;

           }



     }
//here if the user chooses to exit the program
     else if (choice==3){

        cout<<"thank you for choosing our program"<<endl;
        break;
     }

     else{

        cout << "Invalid choice. Please enter a valid option." << endl;
     }

    }


    return 0;
    }




