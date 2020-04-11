#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// space for current and extra books
int NUMBER_OF_BOOKS = 20;

struct bookDetail {
    int index;
    string bookName;
    string authorFirstName;
    string authorLastName;
    string authorFullName;
    string releaseDay;
    string releaseMonth;
    string releaseYear;
    string releaseDate;
    string genre;
    long sales;
    string saleOutput;
};

void loadBook(ifstream& infile1, ifstream& infile2,  bookDetail list[], int bookSize) {
    // for counting total numbers of books
    int count = 0;
    
    // for inputing book name from bookName.txt
    while (getline(infile1, list[count].bookName)) {
        count++;
    }
    
    
    
    // for inputing the rest of the data from bookList.txt
    while(!infile2.eof()) {
        for (int i = 0; i < count; i++) {
            infile2 >> list[i].authorFirstName;
            infile2 >> list[i].authorLastName;
            
            // combine author's name
            list[i].authorFullName = list[i].authorFirstName + " " +
            list[i].authorLastName;
            
            infile2 >> list[i].releaseDay;
            infile2 >> list[i].releaseMonth;
            infile2 >> list[i].releaseYear;
            
            // combine release date
            list[i].releaseDate = list[i].releaseMonth + " " +
            list[i].releaseDay + ", " +
            list[i].releaseYear;
            
            infile2 >> list[i].genre;
            infile2 >> list[i].sales;
            
            
        }
    }
    
}

void displayBook( bookDetail list[], int bookSize) {
    
    // print the header
    cout << "=============================================================" <<
    "=============================================" << endl;
    cout << setw(5) << left << " " << setw(35) << "Book Title" << setw(20) << "Author"
    << setw(20) << "Release Date" << setw(15) << "Genre" << setw(15) << "Sales" << endl;
    cout << "=============================================================" <<
    "=============================================" << endl << endl;
    
    for (int count = 0; count < NUMBER_OF_BOOKS; count++ ) {
        cout << " " << setw(4) << count + 1;
        cout << setw(35) << list[count].bookName;
        cout << setw(20) << list[count].authorFullName;
        cout << setw(20) << list[count].releaseDate;
        cout << setw(15) << list[count].genre;
        cout << setw(15) << list[count].sales << endl << endl;
    };
    
    cout << "=============================================================" <<
    "=============================================" << endl << endl;
}

void searchBook(bookDetail list[], string name) {
    int index;
    for (int count= 0; count < NUMBER_OF_BOOKS; count++ ) {
        if (name == list[count].bookName){
            index=count;
            break;
        }
    }
    cout << name <<" is published by "<< list[index].authorFullName << " and was released on "<< list[index].releaseDate << "."<<endl;
    cout << "It is "<< list[index].genre << " and was sold "<< list[index].sales << "." << endl;
}

void addBook() {
    cout << "add book" << endl;
}

void updateBookIncome(string name, bookDetail list[]) {
    long add_income;
    int index;
    for (int count=0; count < NUMBER_OF_BOOKS; count++){
        if (list[count].bookName == name){
            index=count;
            break;
        }
    }
    cout <<"How much mouney do you want to add to " << list[index].bookName << " ?\n";
    cin >> add_income;
    cout << "Old income: "<< list[index].sales << " and the new income is " << list[index].sales + add_income<< endl;
    list[index].sales += add_income;
    
    
}


int main() {
    
    bookDetail datalist[NUMBER_OF_BOOKS];
    ifstream infileName, infileList;
    infileName.open("bookName.txt");
    infileList.open("bookList.txt");

 string book;

    int userChoice = 5;
    display:
    cout << "========================================" << endl;
    cout << "10 BEST BOOK COLLECTION" << endl;
    cout << "========================================" << endl;
    cout << "[0] Load 10 Books" << endl;
    cout << "[1] Display All Books" << endl;
    cout << "[2] Search book by name" << endl;
    cout << "[3] Add a new book" << endl;
    cout << "[4] Update book's gross income by name" << endl;
    cout << "[5] Menu" << endl;
    cout << "[6] Exit" << endl;
    cout << "========================================" << endl;
    do{
        cout << "menu choice >> ";
        
        int choice;
        cin >> choice;
        cout << endl;
        loadBook(infileName, infileList, datalist, NUMBER_OF_BOOKS);

        switch (choice) {
            case 0:
                NUMBER_OF_BOOKS=10;
                displayBook( datalist, NUMBER_OF_BOOKS);

                break;
                
            case 1:
                NUMBER_OF_BOOKS = 20;
                displayBook(datalist, NUMBER_OF_BOOKS);
                break;
            case 2:
                cin.ignore();
                
                cout << "Enter the book name you want to search : ";
                getline(cin, book);
                searchBook( datalist, book );
                break;
            case 3:
                
                addBook();
                break;
            case 4:
                cin.ignore();
                cout << "Enter the book name you want to add the book's income: ";
                getline(cin,book);
                updateBookIncome(book, datalist);
                break;
            case 5:
            goto display;// go back to line 110 to re-display the menu
            
                break;
            case 6:
            return 0;        }
        
    }while (userChoice >= 0 && userChoice <= 5);
    
    
    infileList.close();
    infileName.close();
    
    
    
    return 0;
    
}

