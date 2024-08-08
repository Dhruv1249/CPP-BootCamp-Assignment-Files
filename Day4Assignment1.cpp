#include <iostream>

using namespace std;

class Book{
    private:
    string title;
    string author;
    int year;
    public:
    Book(string tl, string auth, int yr){
        title = tl;
        author = auth;
        year = yr;
    }

    void displayInfo(){
        cout << "Tile: "<< title<< endl;
        cout << "Author: "<<author<<endl;
        cout << "Year: "<< year<<endl;
    }
};

int main(){
    Book book("Song of Ice And Fire","George R.R Martin",1996);
    book.displayInfo();

}