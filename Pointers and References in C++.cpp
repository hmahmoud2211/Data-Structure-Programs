#include <iostream>
using namespace std;
int main ()
{
    int a = 10, *pa, &ra;
    pa = &a;
    ra = a;
    cout << "a="<<ra <<endl;
    cout << " &a = 10"<<endl;

}
