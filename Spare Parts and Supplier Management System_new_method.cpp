#include <iostream>
using namespace std;
#include <string>
#include <stack> 
#include <list>

class Supplier; // Forward declaration
template <class T>
class supplierBST; // Forward declaration

class SparePart {
public:
    string partName;
    int partNumber, cost;
    string existingParts;
    Supplier* supplierPtr;
    supplierBST <Supplier>* t1;

    SparePart() {
        partName = " ";
        partNumber = 0;
        cost = 0;
        existingParts = " ";
        supplierPtr = nullptr;
    }

    void getdata() {
        cout << "Enter the ID of the part: ";
        cin >> partNumber;

        cout << "Enter the name of the part: ";
        cin >> partName;

        cout << "Enter the cost of the part: ";
        cin >> cost;

        cout << "Enter the existing parts: ";
        cin >> existingParts;

        cout << endl;
    }

    void putdata() {
        cout << "Part Name: " << partName << endl;
        cout << "Part ID: " << partNumber << endl;
        cout << "Cost: " << cost << endl;
        cout << "Existing Parts: " << existingParts << endl;
        cout << endl;
    }

    void linkSupplier(Supplier* supplier) {
        supplierPtr = supplier;
    }

    void modifydata() {
        int choice;
        cout << "Enter the data you want to modify: " << endl;
        cout << "1. Name" << endl;
        cout << "2. Cost" << endl;
        cout << "3. Existing parts" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the new part name: ";
                cin >> partName;
                break;
            case 2:
                cout << "Enter the new cost: ";
                cin >> cost;
                break;
            case 3:
                cout << "Enter the new existing parts: ";
                cin >> existingParts;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << endl;
    }
    
};

class Supplier {
public:
    string supplierName;
    int supplierCode, telephone;
    string address, email;

    Supplier() {
        supplierName = " ";
        supplierCode = 0;
        address = " ";
        telephone = 0;
        email = " ";
    }

    void getdata() {
        cout << "Enter the ID of the supplier: ";
        cin >> supplierCode;

        cout << "Enter the name of the supplier: ";
        cin >> supplierName;

        cout << "Enter the address of the supplier: ";
        cin >> address;

        cout << "Enter the number of the supplier: ";
        cin >> telephone;

        cout << "Enter the email of the supplier: ";
        cin >> email;

        cout << endl;
    }

    void putdata() {
        cout << "Supplier Name: " << supplierName << endl;
        cout << "Supplier Code: " << supplierCode << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Email: " << email << endl;
        cout << endl;
    }

    void modifydata() {
        int choice;
        cout << "Enter the data you want to modify: " << endl;
        cout << "1. Name" << endl;
        cout << "2. Address" << endl;
        cout << "3. Telephone" << endl;
        cout << "4. Email" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the new supplier name: ";
                cin >> supplierName;
                break;
            case 2:
                cout << "Enter the new address: ";
                cin >> address;
                break;
            case 3:
                cout << "Enter the new telephone: ";
                cin >> telephone;
                break;
            case 4:
                cout << "Enter the new email: ";
                cin >> email;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << endl;
    }
};
template<class T>
class TreeNode {
public:
    T data;
    TreeNode<T>* Left;
    TreeNode<T>* Right;

    TreeNode(T s) {
        data = s;
        Right=NULL;
        Left=NULL;
}
};

template<class T>
// Class for Binary Search Tree (BST) of Suppliers
class supplierBST {
public:
    TreeNode<T>* root; //pointer to the root of the tree
    
    supplierBST() 
    {
        root = NULL;
    }

     TreeNode<T>* insertSupplier(TreeNode<T>* r, T s) {
        TreeNode<T>* newnode = new TreeNode<T>(s);

        if (r == NULL) { // if the binary tree is empty
            r = newnode;
        }

        if (s.supplierCode < r->data.supplierCode) {
            r->Left = insertSupplier(r->Left, s);
        } 
        
        else if (s.supplierCode > r->data.supplierCode) {
            r->Right = insertSupplier(r->Right, s);
        }

        return r;
    }

    // Recursive function to perform in-order traversal of the BST
    void inOrderTraversal(TreeNode<T>* node) {
       
        if (node == NULL) 
            return;
        
        inOrderTraversal(node->Left);
            
        // Display supplier information
            node->data.putdata();

        // Display spare parts associated with the supplier
            cout << "Spare Parts:\n";
            root->data.put_data();

            inOrderTraversal(node->right);
        }
    

    // Function to search for a supplier by supplier code
     TreeNode<T>* searchSupplier(int supplierCode) {
        TreeNode<T>* current = root;
        while (current) {
            if (supplierCode == current->data.supplierCode) {
                return &current->data;
            }
            
            else if (supplierCode < current->data.supplierCode) {
                current = current->Left;
            }
            
            else {
                current = current->Right;
            }
        }
        return nullptr;
    }
    
    int minValue(TreeNode<T>* r)
    {
        if(r==NULL)
            return NULL;
        
        else if (r->Left == NULL)
            return r->data.supplierCode;
        
        else return minValue(r->Left);
    }
    
    TreeNode<T>* _delete(TreeNode<T>* root, T v) {
        if (root == NULL) {
            return NULL;
        }

        if (v < root->data.supplierCode) {
            root->Left = _delete(root->Left, v);
        }
        else if (v > root->data.supplierCode) {
            root->Right = _delete(root->Right, v);
        }
        else {
            if (root->Left == NULL) {
                TreeNode<T>* temp = root->Right;
                delete root;
                return temp;
            }
            else if (root->Right == NULL) {
                TreeNode<T>* temp = root->Left;
                delete root;
                return temp;
            }
            else {
                T minValue = this->minValue(root->Right);
                root->data.supplierCode = minValue;
                root->Right = _delete(root->Right, minValue);
            }
        }
        return root;
    }
    
};



template<class T>
class partsBST {
public:
    TreeNode<T>* root; // Pointer to the root of the tree
    
    BST(){
        root = NULL;
    }

    TreeNode<T>* insertSparePart(TreeNode<T>* r, T s) {
        TreeNode<T>* newnode = new TreeNode<T>(s);

        if (r == NULL) { // if the binary tree is empty
            r = newnode;
        }
        else if (s.partNumber < r->data.partNumber) {
            r->Left = insertSparePart(r->Left, s);
        } 
        else if (s.partNumber > r->data.partNumber) {
            r->Right = insertSparePart(r->Right, s);
        }

        return r;
    }

    void inOrderTraversal(TreeNode<T>* node) {
        if (node == NULL) 
            return;
        
        inOrderTraversal(node->Left);
        
        // Display spare part information
        node->data.putdata();
        
        inOrderTraversal(node->Right);
    }

    TreeNode<T>* searchSparePart(int partNumber) {
        TreeNode<T>* current = root;
        while (current) {
            if (partNumber == current->data.partNumber) {
                return &current->data;
            }
            else if (partNumber < current->data.partNumber) {
                current = current->Left;
            }
            else {
                current = current->Right;
            }
        }
        return nullptr;
    }

    int minValue(TreeNode<T>* r) {
        if (r == NULL)
            return NULL;
        else if (r->Left == NULL)
            return r->data.partNumber;
        else
            return minValue(r->Left);
    }

    TreeNode<T>* _delete(TreeNode<T>* root, int v) {
        if (root == NULL) {
            return NULL;
        }

        if (v < root->data.partNumber) {
            root->Left = _delete(root->Left, v);
        }
        else if (v > root->data.partNumber) {
            root->Right = _delete(root->Right, v);
        }
        else {
            if (root->Left == NULL) {
                TreeNode<T>* temp = root->Right;
                delete root;
                return temp;
            }
            else if (root->Right == NULL) {
                TreeNode<T>* temp = root->Left;
                delete root;
                return temp;
            }
            else {
                int minValue = this->minValue(root->Right);
                root->data.partNumber = minValue;
                root->Right = _delete(root->Right, minValue);
            }
        }
        return root;
    }
};

class StackRecorder {
public:
    stack<string> actionStack; // Stack to store user actions
    
    // Function to record user actions as notes
    void recordAction(string action) {
        if (actionStack.size() >= 100) {
            actionStack.pop(); // Remove the oldest action if the stack is full
        }
        actionStack.push(action); // Record the new action
    }

    // Function to display all the recorded notes
    void displayNotes() {
        if (actionStack.empty()) {
            cout << "No actions recorded yet." << endl;
            return;
        }

        cout << "Recorded actions:" << endl;
        stack<string> tempStack = actionStack; // Create a temporary stack for displaying
        while (!tempStack.empty()) {
            cout << tempStack.top() << endl;
            tempStack.pop();
    }
    }
};
int main ()
{
    return 0;
}