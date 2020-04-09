#include <iostream>
#include <string>
using namespace std;

const int NUMBER_OF_MOVIES = 10;

struct bookDetail {
	int index;
	string movieName;
	string releaseDay;
	string releaseMonth;
	string releaseYear;
	string distributor;
	string genre;
	long gross;
	long ticketSold;
};

void loadBook(bookDetail list[], int listSize) {
	
};

void displayBook() {
	cout << "display movie" << endl;
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

int displayMenu() { 
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
	
	cout << "menu choice >> ";
	
	int choice;
	cin >> choice;
	cout << endl;
	
	switch (choice) {
		case 0:;
		case 1: 
			displayBook();
			break;
		case 2:
			searchBook();
			break;
		case 3:
			addBook();
			break;
		case 4:
			updateBookIncome();
			break;
		case 5:
			break;
		case 6:
			break;
	}
	
	return choice;
};

int main() {
	
	int userChoice = 5;

	while (userChoice >= 0 && userChoice <= 5) {
		userChoice = displayMenu();
	};
	
	return 0;
	
}

