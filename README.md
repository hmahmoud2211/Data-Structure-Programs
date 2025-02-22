# Flight and Spare Parts Management System

## Introduction
The **Flight and Spare Parts Management System** is a C++ program that integrates **Flight Management** and **Spare Parts and Supplier Management** using **Linked Lists, Stacks, and Binary Search Trees (BSTs)**. The system allows users to manage flight records, spare parts, and supplier details efficiently.

## Features
### Flight Management System:
- **Linked List Operations:**
  - Add a new flight
  - Delete a flight by ID
  - Display all flights
- **Stack Operations:**
  - Add a new flight (rejects duplicates)
  - View the latest added flight
  - Print all flights in LIFO order
  - Edit an existing flight
  - Delete the latest added flight

### Spare Parts and Supplier Management System:
- **Spare Parts Management:**
  - Add a new spare part
  - Modify spare part details
  - Link spare parts to suppliers
  - Display all spare parts
- **Supplier Management:**
  - Add a new supplier
  - Modify supplier details
  - Search for suppliers by ID
  - Display all suppliers
- **Binary Search Tree (BST) Operations:**
  - Insert spare parts and suppliers into BSTs
  - Delete spare parts and suppliers
  - In-order traversal to display data
- **Stack Operations:**
  - Record user actions (e.g., insert, delete, modify)
  - Display recorded actions in LIFO order

## Technologies Used
- **C++** (Standard Library)
- **OOP Concepts** (Encapsulation, Constructors, Getters/Setters)
- **Data Structures:**
  - **Linked List** for flight management
  - **Stack** for tracking user actions and LIFO operations
  - **Binary Search Tree (BST)** for efficient spare parts and supplier data storage

## Installation & Execution
### Prerequisites:
- C++ Compiler (g++ recommended)
- Any IDE or terminal with C++ support

### Steps:
1. **Clone the Repository**
   ```bash
   git clone https://github.com/your-repo/flight-spare-parts-management.git
   ```
2. **Navigate to the Project Directory**
   ```bash
   cd flight-spare-parts-management
   ```
3. **Compile the Program**
   ```bash
   g++ main.cpp -o management_system
   ```
4. **Run the Program**
   ```bash
   ./management_system
   ```

## Usage
Upon running, the program presents a menu:
1. **Flight Management Operations**
   - Insert new flight
   - Delete a flight
   - Display all flights
2. **Spare Parts Operations**
   - Insert a new spare part
   - Modify spare part details
   - Link spare part to a supplier
   - Display all spare parts
3. **Supplier Operations**
   - Insert a new supplier
   - Modify supplier details
   - Search for a supplier by ID
   - Display all suppliers
4. **Stack Operations**
   - View recorded actions (e.g., insert, delete, modify)
   - Display all actions in LIFO order

## Example Input & Output
```
Welcome to the Flight and Spare Parts Management System!
Menu Options:
1. Flight Management
2. Spare Parts Management
3. Supplier Management
4. Stack Operations
Enter your choice (1-4): 1

Flight Management Options:
1. Insert new flight
2. Delete Flight
3. Display All Flights
4. Close the program
Enter your choice (1-4): 1
Enter the Flight ID: 101
Enter the Flight Model: Boeing 747
Enter the Flight Capacity: 300
Enter the Flight Airline: Emirates
Enter the Flight Destination: New York
Enter the Flight Departure Time: 12:00 PM
Enter the Flight Ticket Price: 500.00
Flight Added Successfully!
```

## Code Overview
### Key Classes:
1. **Flight:**
   - Manages flight details (ID, model, capacity, airline, destination, departure time, price).
   - Supports Linked List and Stack operations.
2. **SparePart:**
   - Manages spare part details (ID, name, cost, quantity).
   - Links spare parts to suppliers.
3. **Supplier:**
   - Manages supplier details (ID, name, address, telephone, email).
4. **supplierBST:**
   - Implements a BST for storing and managing suppliers.
   - Supports insertion, deletion, and in-order traversal.
5. **partsBST:**
   - Implements a BST for storing and managing spare parts.
   - Supports insertion, deletion, and in-order traversal.
6. **StackRecorder:**
   - Records user actions (e.g., insert, delete, modify) using a stack.
   - Displays actions in LIFO order.

### Example Code Snippet:
```cpp
class SparePart {
public:
    string partName;
    int partNumber, cost;
    string existingParts;
    Supplier* supplierPtr;
    supplierBST<Supplier>* t1;

    void getdata() {
        cout << "Enter the ID of the part: ";
        cin >> partNumber;
        cout << "Enter the name of the part: ";
        cin >> partName;
        cout << "Enter the cost of the part: ";
        cin >> cost;
        cout << "Enter the existing parts: ";
        cin >> existingParts;
    }

    void putdata() {
        cout << "Part Name: " << partName << endl;
        cout << "Part ID: " << partNumber << endl;
        cout << "Cost: " << cost << endl;
        cout << "Existing Parts: " << existingParts << endl;
    }
};
```

## Contributions
Feel free to contribute by:
- Reporting issues
- Suggesting improvements
- Adding new features

## License
This project is licensed under the MIT License.

---

This README file now includes both the **Flight Management System** and **Spare Parts and Supplier Management System**, providing a complete overview of the program. Let me know if you need further modifications!

