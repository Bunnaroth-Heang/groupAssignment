// Source: Best Selling Book of 2019 - https://www.theguardian.com/books/2019/dec/31/bestselling-books-2019

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// space for current and extra books
int NUMBER_OF_BOOKS = 20;
static int new_index ;

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
	string sales;
	string saleOutput;
};

void loadBook(ifstream& infile1, ifstream& infile2, bookDetail list[]) {
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
	
	cout << "All movies are loaded" << endl << endl;
	
}

 string allLower(string s){
     string new_s;
     for (int count = 0; count < s.size(); count ++){
         new_s += tolower(s[count]);
         
     }
     return new_s;
 }

string removespace(string in)
{
    string out;
    for(unsigned int i = 0; i < in.size(); i++)
	{
	    if(in[i] != ' ')
		{
		    out += in[i];
		}
	}
    return out;
}

void displayBook( bookDetail list[], int bookSize) {
    
    // print the header
    cout << "=============================================================" <<
			"=============================================" << endl;
			
    cout << setw(5) << left << " " << setw(35) << "Book Title" << setw(20) << "Author"
		 << setw(20) << "Release Date" << setw(15) << "Genre" << setw(15) << "Sales" << endl;
		 
    cout << "=============================================================" <<
			"=============================================" << endl << endl;
    
    for (int count = 0; count < 10; count++ ) {
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
   bool found=0;
	string new_name=allLower(name);
    string new_bookName;
    for (int count= 0; count < NUMBER_OF_BOOKS; count++ ) {
        new_bookName = allLower(list[count].bookName);
       if(removespace(new_name) == removespace(new_bookName)){
            
            new_index = count;
            found=1;
        }
	}
		if (found) {
		cout << endl;	
	
		cout << setw(5) << left << " " << setw(35) << "Book Title" << setw(20) << "Author"
			 << setw(20) << "Release Date" << setw(15) << "Genre" << setw(15) << "Sales" << endl;

		cout << "=============================================================" <<
				"=============================================" << endl;
    
        cout << " " << setw(4) << new_index + 1;
        cout << setw(35) << name;
        cout << setw(20) << list[new_index].authorFullName;
        cout << setw(20) << list[new_index].releaseDate;
        cout << setw(15) << list[new_index].genre;
        cout << setw(15) << list[new_index].sales << endl;
    
		cout << "=============================================================" <<
				"=============================================" << endl << endl;

    } else {
        cout << "The book cannot be found! "<<endl;
	}
}


void addBook(bookDetail list[], int bookSize) {
	int currentBookCount = bookSize;
		
	cout << "Add a new book " << endl << endl;
	cout << "Name: ";
	getline(cin, list[currentBookCount].bookName);
	cout << "Author: ";
    cin.ignore();
	getline(cin, list[currentBookCount].authorFullName);
	cout << "Release Date: ";
    cin.ignore();
	getline(cin, list[currentBookCount].releaseDate);
	cout << "Genre: ";
    cin.ignore();
	getline(cin, list[currentBookCount].genre);
	cout << "Book sold: ";
    cin.ignore();
	getline(cin, list[currentBookCount].sales);
	
	currentBookCount++;
}

void updateBookIncome(string name, bookDetail list[]) {
    string add_income;
    bool isfound=0;
    int index;
    string new_bookName;
    string new_name=allLower(name);
    for (int count=0; count < NUMBER_OF_BOOKS; count++){
        new_bookName=allLower(list[count].bookName);
        if (removespace(new_bookName) == removespace(new_name)){
            index=count;
            isfound=1;
            break;
        }
    }
    if(isfound){
            cout <<"How much mouney do you want to add to " << list[index].bookName << " ?\n";
            cin >> add_income;
            cout << "Old income: "<< list[index].sales << " and the new income is " << add_income<< endl;
            list[index].sales = add_income;
    }
    else {
        cout << "Sorry the book you wanted to update the income is not found on the list"<<endl;
    }


}

int main() {
    bookDetail datalist[NUMBER_OF_BOOKS];
    ifstream infileName, infileList;
    infileName.open("bookName.txt");
    infileList.open("bookList.txt");

	string book;

    int userChoice = 5;
	
	// goto 
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

    do {
        cout << "menu choice >> ";
		
        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 0:
				loadBook(infileName, infileList, datalist);
                break;

            case 1:
                displayBook(datalist, NUMBER_OF_BOOKS);
                break;
				
            case 2:
                cin.ignore();
                cout << "Enter the book name you want to search : ";
                getline(cin, book);
                searchBook( datalist, book );
                	
                    cout << new_index;
                book.clear();
                break;
				
            case 3:
				cin.ignore();
                addBook( datalist, NUMBER_OF_BOOKS);
                break;
				
            case 4:
                cin.ignore();
                cout << "Enter the book name you want to add the book's income: ";
                getline(cin,book);
                updateBookIncome(book, datalist);
                break;
				
            case 5:
				// go back to line 110 to re-display the menu
				goto display;

                break;
            case 6:
				exit (0);
                break;
        
		}
    } while ( userChoice >= 0 && userChoice <= 5 );


    infileList.close();
    infileName.close();

    return 0;
	
}

