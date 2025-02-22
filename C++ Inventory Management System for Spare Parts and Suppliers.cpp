#include <iostream>
using namespace std;


class spareparts
{
    string partname;
    int partnumber;
    double cost;
   string existingParts;

public:
spareparts()
{
   partname= "";
   partnumber=0;
   cost=0;
   existingParts="";
}

//setter
void set_partname(string n)
{
    partname=n;
}
void set_partnumber(int num)
{
    partnumber=num;
}
void set_cost(double c)
{
    cost=c;
}
void set_existingParts(string ep)
{
    existingParts=ep;
}
//geter
string get_partname()
{
    return partname;
}
int get_partnumber()
{
    return partnumber;
}
double get_cost()
{
    return cost;
}
string get_existingParts()
{
    return existingParts;
}

// method to get the input from the user and add it our attribute
void getdata( string name,int numb,double co,string eps )
{
   set_partname (name);
   set_partnumber(numb);
   set_cost(co);
   set_existingParts(eps);
}

 void putdata() {
        cout << "part name : " << get_partname() << endl;
        cout << "part number : " << get_partnumber() << endl;
        cout << "cost : " << get_cost() << endl;
        cout << "existing Parts : " << get_existingParts() << endl;
    }



void modifydata() {
    int choice;
    cout << "1)partname" << endl;
    cout << "2)partnumber" << endl;
    cout << "3)cost" << endl;
    cout << "4)existingParts" << endl;
    cout << "enter the choice you want to edit : ";
    cin >> choice;
    switch (choice) {
        case 1: {
            string m_name;
            cout << "enter the modified data : ";
            cin >> m_name;
            partname = m_name;
            break;
        }
        case 2: {
            int n_number;
            cout << "enter the modified data : ";
            cin >> n_number;
            partnumber = n_number;
            break;
        }
        case 3: {
            double c_cost;
            cout << "enter the modified data : ";
            cin >> c_cost;
            cost = c_cost;
            break;
        }
        case 4: {
            string e_exp;
            cout << "enter the modified data : ";
            cin >> e_exp;
            existingParts = e_exp;
            break;
        }
        default:
            cout << "invalid choice" << endl;
            break;
    }
}
 
 };
 
class supplier
{
    string suppliername;
    int suppliercode;
    string address;
    double telephone;
    string email;

public:
supplier()
{
   suppliername= "";
   suppliercode=0;
   address="";
   telephone=0;
   email="";
}

//setter
void set_suppliername(string sn)
{
    suppliername=sn;
}
void set_suppliercode(int cod)
{
    suppliercode=cod;
}
void set_address(string a)
{
    address=a;
}
void set_telephone(double te)
{
    telephone=te;
}
void set_email(string em)
{
    email=em;
}
//geter
string get_suppliername()
{
    return suppliername;
}
int get_suppliercode()
{
    return suppliercode;
}
string get_address()
{
    return address;
}
double get_telephone()
{
    return telephone;
}
string get_email()
{
    return email;
}
// method to get the input from the user and add it our attribute
void getdata( string supnam,int supcod, string add ,double tele ,string ema  )
{
   set_suppliername(supnam);
   set_suppliercode(supcod);
   set_address(add);
   set_telephone(tele);
   set_email(ema);
}
void putdata ()
{
cout<<"suppliername"<<get_suppliername()<<endl;
cout<<"suppliercode"<<get_suppliercode()<<endl;
cout<<"address"<<get_address()<<endl;
cout<<"telephone"<<get_telephone()<<endl;
cout<<"email"<<get_email()<<endl;
}

void modifydata ()
{
int choise;
 cout<<"1)suppliername"<<endl;
 cout<<"2)suppliercode"<<endl;
 cout<<"3)address"<<endl;
 cout<<"4)telephone"<<endl;
 cout<<"5)email"<<endl;
 cout<<"enter the choice you want to edit : ";
 cin>>choise;
 switch(choise)
 {
     case 1:
     {
    string x_name; 
    cout<<"enter the modified data : ";
    cin>> x_name;
    suppliername=x_name;
     break;
     }
     case 2:
     {
        int c_code; 
    cout<<"enter the modified data : ";
    cin>> c_code;
    suppliercode=c_code;
     break; 
     }
     case 3:
     {
     string a_addre ;
     cout<<"enter the modified data : ";
     cin>>a_addre;
     address=a_addre;
     break; 
 }
 case 4:
 {
     double  t_telep; 
    cout<<"enter the modified data : ";
    cin>> t_telep;
    telephone=t_telep;
     break;
     }
case 5:
    {
    string  e_ema; 
    cout<<"enter the modified data : ";
    cin>> e_ema;
    email=e_ema;
     break;
     }
     default:
     cout<<"invalid choice"<<endl;
    break;
 }
}
 
};

int main ()
{
    return 0;
}