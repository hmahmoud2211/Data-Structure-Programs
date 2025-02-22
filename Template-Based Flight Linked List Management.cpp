#include <iostream>
#include <string>
using namespace std;

// tamplete class to put any data type in the node 
template <class T>
// class Node
class Node{
    // 2 attributes
    public:
        T data;
        Node<T>* next;
        // constructor
        Node(T e){
            data = e;
            next = NULL;
        }
};
// tamplete class to put any data type in the node 
template <class T>
// flight list class
class FlightList{
    // create the head
	Node<T>* head;

    public:
        // constructor 
    	FlightList(){
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
        //  check if the list is empty 
        // and check if the data of the first node = the id he wants
        // then delete the node that has the id he wants to delete 
        if (temp != NULL && temp->data.Flight_ID == id) {
            head = temp->next;
            delete temp;
            return;
        }
        // traversing and it will stop when he found the id
        while (temp != NULL && temp->data.Flight_ID != id) {
            prev = temp;
            temp = temp->next;
        }
        // if he doesn't found the id in the list he will print not found 
        if (temp == NULL) 
        {
            cout << "the id is not found"<<endl;
        }
        // delete the node
        prev->next = temp->next;
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
    }
    	
};