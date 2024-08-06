#include <iostream>
#include <cmath>
using namespace std;

int squreroot( int a){
    return sqrt(a);
}

int main(){
    int a;
    cout << "Enter a digit: ";
    cin >> a;
    cout << "Square root of the entered digit is: " <<squreroot(a);
}