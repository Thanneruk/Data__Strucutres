#include <iostream>
using namespace std;
int main() {

    int a[] = { 8,7,6,5,2,4,1,3,9 };
    int getArrayLength = sizeof(a) / sizeof(int);
    for (int i = 0; i < getArrayLength; i++)//up unitl the length
    {
        for (int j = 0; j < getArrayLength - 1; j++) {//up until last but one
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    //printing
    for (int i = 0; i < getArrayLength; i++) {
        cout << a[i];
    }

}