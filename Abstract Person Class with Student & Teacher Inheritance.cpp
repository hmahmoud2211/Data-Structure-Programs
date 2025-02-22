#include <iostream>
using namespace std;
#include <string>
// parent class
class person{ 
    // atterpute
    protected :
        string name = "unkown";
    public:
    // methods
        void set_name(string n)
        {
            name = n;
        }
        void display_name()
        {
            cout << name;
        }
        // aptract
        virtual void display_info()=0;
};
// inhertance
class Student : public person{
    // apitrude 
    private:
    int student_ID = 0;
    public :
    // methods
    void set_ID (int id)
    {
        student_ID = id;
    }
    void update_name()
    {
        name = "student";
    }
    void display_info(){
        cout << student_ID ;
        cout << name ;
    }
};
// 
    class Teacher : public person{
    private:
    string subject = "unkown";
    public :
    void set_subject (string s)
    {
        subject = s;
    }
    void update_name()
    {
        name = "teacher";
    }
     void display_info(){
        cout << subject ;
        cout << name ;
    }
};

int main ()
{
    Student s;
    Teacher t;
    s.update_name();
    s.display_info();
    t.update_name();
    t.display_info();
}