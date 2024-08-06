#include <iostream>

using namespace std;

int sum( int a,int b, int c){
    return a +  b + c;
}
int main(){
    int a,b,c;
    cout << "Enter number 1: ";
    cin >> a;
    cout << "Enter number 2: ";
    cin >> b;
    cout << "Enter number 3: ";
    cin >> c;
    cout << "Sum of the three numbers is: " << sum(a,b,c);
}