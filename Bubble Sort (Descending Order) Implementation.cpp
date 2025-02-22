#include <iostream>
using namespace std;
void bubble(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main ()
{
    int a[]={2,5,4,3,1};
    bubble (a,5);
    for (int i = 0;i<5;i++)
    {
        cout << a[i] << " ";
    }
}