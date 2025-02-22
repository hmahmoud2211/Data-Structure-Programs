#include<string>
#include <iostream>
using namespace std;
template <class T>
class Node{

public:
//---------data---------------
T data;
//----------pointers----------
Node<T>* next;
Node<T>* left;
Node<T>* right;

Node(T v){
data=v;
next=left=right=NULL;
}
Node(){
data=NULL;
next=left=right=NULL;
}
};
// Class for Supplier
class Supplier
{
public:
    string Supplier_name;
    string Supplier_address;
    string Supplier_email;
    int id;
    int Supplier_telephone;
    // ... (other member variables)

    // Setters and getters
    void setter_supplier_name(string supplier_namee);
    void setter_Supplier_address(string addresss);
    void setter_Supplier_email(string emailll);
    void setter_Supplier_code(int code);
    void setter_Supplier_telephone(int telephonenumber);

    string getter_supplier_name();
    string getter_Supplier_address();
    string getter_Supplier_email();
    int getter_id();
    int getter_Supplier_telephone();

    // Functions
    void put_data();
    void modify_data();
    void get_data();
    // ... (other member functions)
};
template <class T>

class BST
{
public:
	Node<T>* root;

	BST() //complexity : O(1)
	{
		root = NULL;
	}

	Node<T>* Insert(Node<T>* root, T item) //complexity : O(n)
    {
        if (root == NULL)
        {
            Node<T>* newnode = new Node<T>(item);
            return newnode;
        }
        else if (item.getter_id() < root->data.getter_id())
        {
            root->left = Insert(root->left, item);
        }
        else if (item.getter_id() > root->data.getter_id())
        {
            root->right = Insert(root->right, item);
        }

        return root;
    }

    void Insert(T item) //complexity : O(n)
    {
        root = Insert(root, item);
    }


	void Inorder(Node<T>* root) // left->root -> right //complexity : O(n)
	{
		if (root == NULL)
			return;

		Inorder(root->left);
        root->data.put_data();
		Inorder(root->right);
	}

	Node<T>* Search(Node<T>* root, int key) //complexity : O(n)
	{
		if (root == NULL)
			return NULL;
		else if (root->data.id == key)
			return root;
		else if (key < root->data.id)
			return	Search(root->left, key);
		else
			return Search(root->right, key);
	}

	Node<T>* Search(int key) //complexity : O(n)
	{
		Node<T>* result = Search(root, key);

		if (result == NULL)
        {

            return NULL;
        }
		else
        {
            // root->data.put_data();
            return result;
        }

	}

	Node<T>* Findmin(Node<T>* root) //complexity : O(n)
	{
		if (root == NULL)
			return NULL;
		else if (root->left == NULL)
			return root;
		else
			return Findmin(root->left);
	}

	Node<T>* Findmax(Node<T>* root) //complexity : O(n)
	{
		if (root == NULL)
			return NULL;
		else if (root->right == NULL)
			return root;
		else
			return Findmax(root->right);
	}

	Node<T>*  Delete(Node<T>* root, int key) //complexity : O(n)
	{
		if (root == NULL) // Empty Tree
			return NULL;
		if (key < root->data.id) // Item exists in left sub tree
			root->left = Delete(root->left, key);
		else if (key > root->data.id) // item exists in right sub tree
			  root->right =Delete(root->right, key);
		else
		{
			if (root->left == NULL && root->right == NULL) // leaf node
				root = NULL;
			else if (root->left != NULL && root->right == NULL) // one child on the left
			{
				root->data = root->left->data;
				delete root->left;
				root->left = NULL;
			}
			else if (root->left == NULL && root->right != NULL) // one child on the right
			{
				root->data = root->right->data;
				delete root->right;
				root->right = NULL;
			}
			else
			{
				Node<T>* max = Findmax(root->left);
				root->data = max->data;
			   root->left=	Delete(root->left, max->data.id);

			}

		}
		return root;
	}
Node<T>* edit(Node<T>* root, int the_id, T newData)  {  //complexity : O(n)
    if (root == NULL)
        return NULL;
    else if (root->data.getter_id() == the_id) {
        root->data = newData;
        return root;
    }
    else if (the_id < root->data.getter_id())
        return edit(root->left, the_id, newData);
    else
        return edit(root->right, the_id, newData);
}
};
template <class T>
class node_linked_list
{
public:
node_linked_list *next;
T data;
node_linked_list(T d){ //complexity : O(1)
    next=NULL;
    data=d;
}
};
// tamplete class to put any data type in the node
template <class T>
// class list
class List {

    public:
    // create the head
	node_linked_list<T>* head;
        // constructor
    	List() //complexity : O(1)
        {
    	    head= NULL;
    	}
        void insert(T data) { //complexity : O(n)
            // create new node
        node_linked_list<T>* node_1 = new node_linked_list<T>(data);
        // check the code is empty or not
        if (head == NULL)
        {
            head = node_1;
        }
        // add the new node to list
        else {
            node_linked_list<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node_1;
        }
    }

    void Delete(int d_id) { //complexity : O(n)
    node_linked_list<T>* temp = head;
    node_linked_list<T>* prev = NULL;

    // Check if the list is empty
    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    // Check if the data of the first node matches the id to delete
    if (head->data.id == d_id) {
        head = temp->next;
        delete temp;
        return;
    }

    // Traverse the list to find the node with the specified id
    while (temp != NULL && temp->data.id != d_id) {
        prev = temp;
        temp = temp->next;
    }

    // If the id is not found in the list
    if (temp == NULL) {
        cout << "Flight with ID " << d_id << " not found\n";
        return;
    }

    // Update the next pointer of the previous node to skip the node to be deleted
    prev->next = temp->next;

    // Delete the node
    delete temp;
}

    // display method
    void DisplayAll() { //complexity : O(n)
        if(head==NULL){
            cout<<"the list is still empty"<<endl;
        }
        else{// make temp pointer
        node_linked_list<T>* temp = head;
        // display the list by traversing
        while (temp != NULL) {
            temp->data.put_data();
            temp = temp->next;
        }
        }
        cout << "the end of the node !"<<endl;
        cout << "\n";
    }

    void edit (T new_data, int the_id){ //complexity : O(n)
     if (head==NULL)
    {
        cout<<"the list is empty";
    }
    else {
        node_linked_list<T> *newnode= new node_linked_list<T>(new_data);
        node_linked_list<T>* temp = head;
        node_linked_list<T> * prev = NULL;
        temp= head;
        while (temp->data.id!= the_id){
            prev=temp;
            temp=temp->next;
        }
        newnode->next=temp->next;
        prev->next=newnode;
        delete temp;
    }
}
// Function to search for a node with a specific ID
    node_linked_list<T>* search_by_id(int targetId) { //complexity : O(n)
        node_linked_list<T>* current = head;
        while (current != nullptr) {
            if (current->data.id == targetId) {
                // Node with the specified ID found
                return current;
            }
            current = current->next;
        }

        // Node with the specified ID not found
        return nullptr;
    }
};
// Class for Spare_parts
class Spare_parts
{
public:
    int id, quantity;
    float cost;
    string part_name;
    Supplier s1;
    List <Supplier> t2;
    BST <Supplier> T1;

    // Setters and getters
    void setter_id(int idd);
    void setter_quantity(int qty);
    void setter_cost(float cst);
    void setter_part_name(string partname);

    string getter_part_name();
    float getter_cost();
    int getter_id();
    int getter_quantity();

    // Functions
    void put_data();
    void modify_data();
    void get_data();
    void add_supplier();
    void tree_suplier();
    void Print_suplier();
    void linkedlist();
    void Print_suplier_linked_list();
};


class Node_stack
{
public:
Node_stack *next;
string data;
    Node_stack(string dataa){ //complexity : O(1)
        next=NULL;
        data=dataa;
    }
};
class stack
{

public:
    Node_stack* Top;
    // Constructor to initialize the stack
    stack()
    {
        Top = nullptr;
    }
    // check is the stack empty or not
    bool IsEmpty() { //complexity : O(1)
        return (Top == nullptr);
    }

    // Methods that push
void Push(string data) { //complexity : O(1)
    Node_stack* Node1 = new Node_stack(data);
    if (IsEmpty()) {
        Top = Node1;
        return;
    }
    Node1->next = Top;
    Top = Node1;
}


    void Pop() { //complexity : O(1)
        if (IsEmpty())
        {
            cout << "Stack is empty. Cannot delete." << endl;
            return;
        }

        Node_stack* temp = Top;
        Top = Top->next;
        delete temp;
    }

    void PrintStack() { //complexity : O(n)
        if(IsEmpty()){
            cout<<"the history is empty"<<endl;
        }
        else{
        Node_stack* current = Top;
        while (current!= NULL){
             cout << current->data<< endl;
             current = current->next;
        }
        }

    }
    void peek ()
    {
        if (IsEmpty())
        {
            cout<<"the stack is empty"<<endl;
        }
        return Top;
    }

 void insert_stack() { //complexity : O(1)
    Push("data is inserted ");
}

void delete_stack() { //complexity : O(1)
    Push("data is deleted ");
}

void edit_stack() { //complexity : O(1)
    Push("data is edited ");
}


};


class queue{
    public:
Node_stack* front;
Node_stack* rear;

queue(){ //complexity : O(1)
    front=rear=NULL;
}

void enqueue(string item){ //complexity : O(1)
Node_stack* newNode= new Node_stack(item);

if (front==NULL && rear == NULL){

    front=rear=newNode;
}
else{

    rear->next=newNode;
    rear=newNode;


}

}

void edit_inprogress(){ //complexity : O(1)
enqueue( "modify is in progress");
}
void insert_inprogress(){ //complexity : O(1)
    enqueue("insert is in progress");
}
void delete_inprogress(){ //complexity : O(1)
    enqueue("delete is in progress");
}

void display() //complexity : O(n)
		{
		    if(front==NULL){
                cout<<"LOG is empty"<<endl;
		    }
		    else{
			Node_stack *tmp = front;
			while(tmp != NULL)
			{
				cout << tmp->data<<endl;
				tmp = tmp->next;
			}
			}
		}

};

void Supplier::setter_supplier_name(string supplier_namee){ //complexity : O(1)
    Supplier_name = supplier_namee;
}
void Supplier::setter_Supplier_address(string addresss) { //complexity : O(1)
    Supplier_address=addresss;
}
void Supplier::setter_Supplier_email(string emailll) { //complexity : O(1)
    Supplier_email=emailll;
}

void Supplier::setter_Supplier_code(int code) { //complexity : O(1)
    id=code;
}
void Supplier::setter_Supplier_telephone(int telephonenumber) { //complexity : O(1)
    Supplier_telephone=telephonenumber;
}
//-----------------------getters-------------------------------
string Supplier:: getter_supplier_name() { //complexity : O(1)
    return Supplier_name;
}
string Supplier:: getter_Supplier_address() { //complexity : O(1)
    return Supplier_address;
}
string Supplier:: getter_Supplier_email() { //complexity : O(1)
    return Supplier_email;
}

int Supplier:: getter_id() { //complexity : O(1)
    return id;
}
int Supplier:: getter_Supplier_telephone() { //complexity : O(1)
    return Supplier_telephone;
}
//----------------------------functions------------------------
void Supplier:: put_data() { //complexity : O(1)
    cout<<"The supplier name is : "<<getter_supplier_name()<<endl;
    cout<<"The supplier code is : "<<getter_id()<<endl;
    cout<<"The supplier address : "<<getter_Supplier_address()<<endl;
    cout<<"The supplier email : "<<getter_Supplier_email()<<endl;
    cout<<"The supplier telephone : "<<getter_Supplier_telephone()<<endl;
}

void Supplier:: modify_data(){ //complexity : O(1)
    cout << "Enter the new supplier name:\n";
    string supl_name;
    cin>>supl_name;
    setter_supplier_name(supl_name);

    cout << "Enter the new supplier address:\n";
    string address_new;
    cin>>address_new;
    setter_Supplier_address(address_new);

    cout << "Enter the new supplier email:\n";
    string supl_email;
    cin>>supl_email;
    setter_Supplier_email(supl_email);

    cout << "Enter the new supplier code:\n";
    int codee;
    cin>>codee;
    setter_Supplier_code(codee);

    cout << "Enter the new supplier telephone:\n";
    int tele;
    cin>>tele;
    setter_Supplier_telephone(tele);
}
void Supplier:: get_data(){ //complexity : O(1)
    cout << "Enter the supplier name:\n";
    string supl_name;
    cin>>supl_name;
    setter_supplier_name(supl_name);

    cout << "Enter the supplier address:\n";
    string address_new;
    cin>>address_new;
    setter_Supplier_address(address_new);

    cout << "Enter the supplier email:\n";
    string supl_email;
    cin>>supl_email;
    setter_Supplier_email(supl_email);

    cout << "Enter the supplier code:\n";
    int codee;
    cin>>codee;
    setter_Supplier_code(codee);

    cout << "Enter the supplier telephone:\n";
    int tele;
    cin>>tele;
    setter_Supplier_telephone(tele);
}

//------------functions of spare parts class------------
void Spare_parts::setter_id(int idd){ //complexity : O(1)
    id=idd;
}
void Spare_parts::setter_quantity(int qty) { //complexity : O(1)
    quantity =qty;
}
void Spare_parts::setter_cost(float cst){ //complexity : O(1)
    cost=cst;
}
void Spare_parts::setter_part_name(string partname){ //complexity : O(1)
    part_name=partname;
}
//-------------------------getters-------------------------
string Spare_parts::getter_part_name(){ //complexity : O(1)
    return part_name;
}

float Spare_parts::getter_cost(){ //complexity : O(1)
    return cost;
}

int Spare_parts::getter_id(){ //complexity : O(1)
    return id;
}
int Spare_parts::getter_quantity(){ //complexity : O(1)
    return quantity;
}
//-----------------------functions-------------------------
void Spare_parts::put_data() { //complexity : O(1)
    cout << "Part Name : "<< getter_part_name() << endl;
    cout <<"part id : "<<getter_id()<<endl;
    cout << "Cost of Part : " << getter_cost() <<endl;
    cout << "Quantity Available : " << getter_quantity() << "\n" ;
}

void Spare_parts::modify_data(){ //complexity : O(1)
    cout<<"enter the new cost of the spare part :"<<endl;
    float new_cost;
    cin>>new_cost;
    setter_cost(new_cost);

    cout<<"enter the new id of the spare part :"<<endl;
    int id_new;
    cin>>id_new;
    setter_id(id_new);

    cout<<"enter the new quantity of the spare part :"<<endl;
    int quantity_new;
    cin>>quantity_new;
    setter_quantity(quantity_new);
}

void Spare_parts::get_data(){ //complexity : O(1)
    cout <<"enter the name of the spare part : "<<endl;
    string name;
    cin>>name;
    setter_part_name(name);

    cout<<"enter the cost of the spare part : "<<endl;
    float new_cost;
    cin>>new_cost;
    setter_cost(new_cost);

    cout<<"enter the id of the spare part : "<<endl;
    int id_new;
    cin>>id_new;
    setter_id(id_new);

    cout<<"enter the quantity of the spare part : "<<endl;
    int quantity_new;
    cin>>quantity_new;
    setter_quantity(quantity_new);


}
// Tree manipulation
void Spare_parts::add_supplier () //complexity : O(1)
{
    cout << "Enter the data of the suplier : "<< endl;
    s1.get_data();
}


void Spare_parts::tree_suplier() //complexity : O(n LOG n)
{

    cout << "Enter the number of supliers : ";
    int num;
    cin >> num;
    for (int i = 0 ; i <num ;i++)
    {
        add_supplier();
        T1.Insert(s1);
    }
}
void Spare_parts::Print_suplier () //complexity : O(n)
{
    T1.Inorder(T1.root);
}

//linked list manipulation


void Spare_parts::linkedlist(){  //complexity : O(n)
cout<< "enter the number of supliers : ";
int num;
cin>>num;
for (int i=0; i<num;i++){
    add_supplier();
    t2.insert(s1);
}
}

void Spare_parts::Print_suplier_linked_list(){ //complexity : O(n)
    t2.DisplayAll();
}

int main() {
    cout << "Welcome to the program, client." << endl;//o(1)
    int continuee=1;//o(1)
    List<Spare_parts> obj1;//o(1)
    BST <Spare_parts> obj2;//o(1)
    queue obj3;//o(1)
    stack obj4;//o(1)
    queue obj5;//o(1)
    stack obj6;//o(1)
    while (continuee==1) {//o(n)
    cout << "please choose the mode" << endl;//o(1)
    cout << "1) linked list" << endl;//o(1)
    cout << "2) tree " << endl;//o(1)
    int switche;//o(1)
    cin >> switche;//o(1)


    switch (switche) {
       case 1://o(1)
       {
            cout << "Welcome to the linked-list mode" << endl;//o(1)

            cout << "please enter the mode operation" << endl;//o(1)
            cout << "1-insert" << endl;//o(1)
            cout << "2-delete" << endl;//o(1)
            cout << "3-display all" << endl;//o(1)
            cout << "4-edit" << endl;//o(1)
            cout << "5- print the supplier"<<endl;//o(1)
            cout << "6- close the program"<<endl;//o(1)
            cout << "7- history" << endl;//o(1)
            cout << "8- log part "<<endl;//o(1)
            cout << "9- add new supplier for spare part "<<endl;//o(1)
            cin >> switche;//o(1)

            switch (switche) {
                case 1://o(n)
                    {
                        Spare_parts obj_spare;//o(1)
                        obj_spare.get_data();//o(n)
                        obj_spare.linkedlist();//o(n)
                        obj1.insert(obj_spare);//o(n)
                        obj4.insert_stack();//o(1)
                        obj3.insert_inprogress();//o(1)
                        break;
                    }
                case 2:
                    {


                    int del_id;//o(1)
                    cout<<"please enter the id of spare part to delete"<<endl;//o(1)
                    cin>>del_id;//o(1)
                    obj1.Delete(del_id);//o(n)
                    obj4.delete_stack();//o(1)
                    obj3.delete_inprogress();//o(1)
                    break;
                    }
                case 3:
                    {
                    obj1.DisplayAll();//o(n)
                    break;
                    }
                case 4:
                    {
                    Spare_parts obj_spare;//o(1)
                    obj_spare.get_data();//o(1)
                    int spare_id;//o(1)
                    cout<<"please enter th id of the part you want to edit"<<endl;//o(1)
                    cin>>spare_id;//o(1)
                    obj1.edit(obj_spare,spare_id);//o(n)
                    obj4.edit_stack();//o(1)
                    obj3.edit_inprogress();//o(1)
                    break;//o(1)
                    }
                case 5:
                    {

                int s_id;//o(1)
                cout << "Enter the id of spare part you want to find : "<<endl;//o(1)
                cin >> s_id;//o(1)
                node_linked_list<Spare_parts>*node_part;//o(1)
                node_part=obj1.search_by_id(s_id);//o(n)
                if(node_part==NULL){//o(1)
                    cout<<"this spare part ID does not exist"<<endl;//o(1)
                }
                node_part->data.Print_suplier_linked_list();//o(n)
                break;//o(1)
                    }
                case 6 :
                    {
                cout<<"thx for using the program";//o(1)
                continuee=0;//o(1)
                break;//o(1)
                    }
                case 7:
                    {
                cout << "your history is : "<<endl;//o(1)
                obj4.PrintStack();//o(n)
                 break;//o(1)
                    }

                case 8:
                    {
                cout << "your log is : "<<endl;//o(1)
                obj5.display();//o(n)
                break;//o(1)
                    }

                case 9:
                    {
                    int s_id;//o(1)
                cout << "Enter the id of spare part you want to add a supplier for : "<<endl;//o(1)
                cin >> s_id;//o(1)
                node_linked_list<Spare_parts>*node_part;//o(1)
                node_part=obj1.search_by_id(s_id);
                if (node_part==NULL){//o(1)
                    cout<<"this spare part id does not exist"<<endl;//o(1)
                }
                node_part->data.linkedlist();//o(n)
                break;//o(1)
                    }
                default:
                    {
                    cout<<"Invalid input, please try again"<<endl;//o(1)
                    break;//o(1)
                    }

                    }
                    break;//o(1)
       }
        case 2:{
            cout << "Welcome to the tree mode" << endl;//o(1)
            cout << "please enter the mode operation" << endl;//o(1)
            cout << "1-insert" << endl;//o(1)
            cout << "2-delete" << endl;//o(1)
            cout << "3-display all" << endl;//o(1)
            cout << "4-edit" << endl;//o(1)
            cout << "5-display suplier"<<endl;//o(1)
            cout << "6-close the program"<<endl;//o(1)
            cout << "7-history"<<endl;//o(1)
            cout << "8- log part "<<endl;//o(1)
            cout << "9- add new supplier for spare part "<<endl;//o(1)
            cin >> switche;//o(1)
            switch (switche)
            {
            case 1:
            {
                Spare_parts obj_temp;//o(1)
                obj_temp.get_data();//o(1)
                obj_temp.tree_suplier();//o(nlogn)
                obj2.Insert(obj_temp);//o(n) best case o(logn)
                obj6.insert_stack();//o(1)
                obj5.insert_inprogress();//o(1)
                break;//o(1)
            }
            case 2:
            {
                int id_main;//o(1)
                cout << "Please Enter The ID of the node you want to delete : "<<endl;//o(1)
                cin>>id_main;//o(1)
                obj2.Delete(obj2.root,id_main);//o(n) best case o(logn)
                obj6.delete_stack();//o(1)
                obj5.delete_inprogress();//o(1)
                break;//o(1)
            }
            case 3:
            {
                if(obj2.root==NULL){//o(1)
                    cout<<"the tree is still empty"<<endl;//o(1)
                }
                else{
                obj2.Inorder(obj2.root);//o(n)
                }

                break;//o(1)
            }
            case 4:
            {
                Spare_parts obj_temp;//o(1)
                obj_temp.get_data();//o(1)
                int id_main;//o(1)
                cout << "Please Enter The ID of the node you want to delete : "<<endl;//o(1)
                cin>>id_main;//o(1)
                obj2.edit(obj2.root,id_main,obj_temp);//o(n) best case o(logn)
                obj6.edit_stack();//o(1)
                obj5.edit_inprogress();//o(1)
                break;//o(1)
            }
            case 5:
            {
                int s_id;//o(1)
                cout << "Enter the id of spare part you want to find : "<<endl;//o(1)
                cin >> s_id;//o(1)
                Node<Spare_parts>*node_part;//o(1)
                node_part=obj2.Search(s_id);//o(n) best case o(logn)
                if(node_part==NULL){//o(1)
                cout<<"this spare part ID does not exist"<<endl;//o(1)
                }
                else{
                node_part->data.Print_suplier();//o(n)
                }
                break;//o(1)
            }
            case 6:
            {
                 cout<<"thx for using the program";//o(1)
                continuee=0;//o(1)
                break;//o(1)
            }
            case 7:
            {
                cout << "your history is : "<<endl;//o(1)
                obj6.PrintStack();//o(n)
                break;//o(1)
            }
            case 8:
            {
                cout << "your log is : "<<endl;//o(1)
                obj5.display();//o(n)
                break;
            }
            case 9:
                {
                   int s_id;//o(1)
                cout << "Enter the id of spare part you want to add a supplier for : "<<endl;//o(1)
                cin >> s_id;//o(1)
                Node<Spare_parts>*node_part;//o(1)
                node_part=obj2.Search(s_id);//o(n) best case o(logn)
                if (node_part==NULL){//o(1)
                    cout<<"this spare part id does not exist"<<endl;//o(1)
                }
                node_part->data.tree_suplier();//o(nlogn)
                break;//o(1)
                }
           default:
           cout << "Invalid input!" << endl;//o(1)
            break;//o(1)
            }
            break;//end of switch //o(1)
    }
            default:
                cout<<"invalid input!, please try again"<<endl;//o(1)
                break;//o(1)
    }
    }
    }