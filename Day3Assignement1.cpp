#include <iostream>

using namespace std;

int main(){

    int a,b,c;
    int *ptr1 = &a;
    int *ptr2 = &b;
    int *ptr3 = &c;

    *ptr1 = 10;
    *ptr2 = 20;
    *ptr3 = 100;

    cout << *ptr1+*ptr2+*ptr3;

}