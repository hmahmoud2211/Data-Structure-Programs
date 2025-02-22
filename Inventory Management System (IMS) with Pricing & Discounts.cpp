#include <iostream>
using namespace std;
#include <string>

class IMS {
    // private 
    private:
        string P_Name;
        double P_Price;
        int P_Quantity;
        
    // public    
    public:
    // Defult constractor
    IMS ()
    {
        P_Name = "napkins";
        P_Price = 14;
        P_Quantity = 10;
    }
    
    
    // paramatize constractor 
    IMS (string P_Name, double P_Price,int P_Quantity)
    {
       this -> P_Name = P_Name;
       this -> P_Price = P_Price;
       this -> P_Quantity = P_Quantity;
    }

    // setter 
    void setP_Name (string n)
    {
        P_Name = n;
    }
    
    void setP_Price (double p)
    {
        P_Price = p;
    }
    void setP_Quantity (int q)
    {
        P_Quantity = q;
    }
    
    
    //getter
    string getP_Name ()
    {
        return P_Name;
    }
    double getP_Price ()
    {
        return P_Price;
    }
    int getP_Quantity ()
    {
        return P_Quantity;
    }
    
    
    // calculate the dozen price 
    double CalculateDozenPrice() 
    {
       double dozenprice = P_Price * 12;
        return dozenprice ;
    }
    
    
    // calculate the total price 
    // check if it's bigger than 12 to give dicount
    double CalculateTotalPrice() 
    {
        double tot = P_Price * P_Quantity;
        cout << "the price without discount : "<< tot << endl ;
        if (P_Quantity > 12)
        {
            return tot -= (tot*0.20) ;
        }
            return  tot;
    }
       
};
// end the class 





int main() {
    
    
    // declare the class 
    IMS item1("hazem",700,20) , item2;
    // using the first declared item1 by parametize constractor
    cout << "Product Name: " << item1.getP_Name () << endl;
    double price;
    cout << "Enter the price: ";
    cin >> price ;
    item1.setP_Price(price);
    cout << "Product Price: $" << item1.getP_Price () << endl;
    cout << "Product Quantity: " << item1.getP_Quantity () << endl;
    cout << "Product for a Dozen: $" << item1.CalculateDozenPrice() << endl;
    cout << "Total Price: $" << item1.CalculateTotalPrice() << endl;
    
    // leave space 
    cout << endl;
    cout << endl;
    // using the second declared item2 by parametize constractor
    cout << "Product Name: " << item2.getP_Name () << endl;
    cout << "Product Price: $" << item2.getP_Price () << endl;
    cout << "Product Quantity: " << item2.getP_Quantity () << endl;
    cout << "Product for a Dozen: $" << item2.CalculateDozenPrice() << endl;
    cout << "Total Price: $" << item2.CalculateTotalPrice() << endl;
    return 0;
}