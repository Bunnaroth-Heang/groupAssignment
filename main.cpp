// Source: Best Selling Book of 2019 - https://www.theguardian.com/books/2019/dec/31/bestselling-books-2019

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

void loadBook(ifstream& infile1, ifstream& infile2, bookDetail nameList[], bookDetail list[], int bookSize) {
	// for counting total numbers of books
	int count = 0;
	
	// for inputing book name from bookName.txt
	while (getline(infile1, nameList[count].bookName)) {
		count++;
	}
	
	cout << nameList[2].bookName << endl;
		
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
	
};

void displayBook(bookDetail nameList[], bookDetail list[], int bookSize) {
	
	// print the header 
	cout << "=============================================================" <<
			"=============================================" << endl;
	cout << setw(5) << left << " " << setw(35) << "Book Title" << setw(20) << "Author" 
		 << setw(20) << "Release Date" << setw(15) << "Genre" << setw(15) << "Sales" << endl;
	cout << "=============================================================" <<
			"=============================================" << endl << endl;
		 
	for (int count = 0; count < 10; count++ ) {
		cout << " " << setw(4) << count + 1;
		cout << setw(35) << nameList[count].bookName;
		cout << setw(20) << list[count].authorFullName;
		cout << setw(20) << list[count].releaseDate;
		cout << setw(15) << list[count].genre;
		cout << setw(15) << list[count].sales << endl << endl; 
	};
	
	cout << "=============================================================" <<
			"=============================================" << endl << endl;
}

void searchBook() {
	cout << "search movie" << endl;
}

void addBook() {
	cout << "add movie" << endl;
}

void updateBookIncome() {
	cout << "update movie income" << endl;
}

//int displayMenu() { 
//	cout << "========================================" << endl;
//	cout << "10 BEST BOOK COLLECTION" << endl;
//	cout << "========================================" << endl;
//	cout << "[0] Load 10 Books" << endl;
//	cout << "[1] Display All Books" << endl;
//	cout << "[2] Search book by name" << endl;
//	cout << "[3] Add a new book" << endl;
//	cout << "[4] Update book's gross income by name" << endl;
//	cout << "[5] Menu" << endl;
//	cout << "[6] Exit" << endl;
//	cout << "========================================" << endl;
//	
//	cout << "menu choice >> ";
//	
//	int choice;
//	cin >> choice;
//	cout << endl;
//	
//	switch (choice) {
//		case 0:;
//		case 1: 
//			displayBook();
//			break;
//		case 2:
//			searchBook();
//			break;
//		case 3:
//			addBook();
//			break;
//		case 4:
//			updateBookIncome();
//			break;
//		case 5:
//			break;
//		case 6:
//			break;
//	}
//	
//	return choice;
//};

int main() {
//	
//	int userChoice = 5;
//
//	while (userChoice >= 0 && userChoice <= 5) {
//		userChoice = displayMenu();
//	};
	ifstream infileName, infileList;
	infileName.open("bookName.txt");
	infileList.open("bookList.txt");
	
	bookDetail nameLine[NUMBER_OF_BOOKS];
	bookDetail dataList[NUMBER_OF_BOOKS];
	
	loadBook(infileName, infileList, nameLine, dataList, NUMBER_OF_BOOKS);
	
	infileName.close();
	
	displayBook(nameLine, dataList, NUMBER_OF_BOOKS);
	
	return 0;
	
}

