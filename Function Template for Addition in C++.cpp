#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>
T add (T x,T y)
{
    return x+y;
}
int main ()
{
    cout << add(3.5,5.6)<<endl;
    cout << add(3,5)<<endl;
    cout << add(3.5,5)<<endl;

}