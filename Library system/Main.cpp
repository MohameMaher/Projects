#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Author {
	string name, email;
public:
	Author() {}
	Author(string name, string email) {
		this->name = name;
		this->email = email;
	}
	void setAuthorname(string name) {
		this->name = name;
	}
	void setAuthorEmail(string email) {
		this->email = email;
	}
	string getAuthorName() {
		return name;
	}
	string getAuthorEmail() {
		return email;
	}
};

class Book {
	string title;
	Author writer;
	bool status;
	int id = 0;
	static int idhelper;
public:
	Book(){
		this->status = true;
		this->id = ++idhelper;
	}
	Book(string title, Author writer) {
		this->title = title;
		this->writer = writer;
		this->status = true;
		this->id = ++idhelper;
	}
	void setBookTitle(string title) {
		this->title = title;
	}
	void setBookAuthor(Author writer) {
		this->writer = writer;
	}
	void setBookStatus(bool status) {
		this->status = status;
	}
	string getBookTitle() {
		return title;
	}
	Author getBookWriter() {
		return writer;
	}
	bool getBookStatus() {
		return status;
	}
	int  getBookID() {
		return this->id;
	}
	void DispalyBook() {
		cout << "Book Title : " << getBookTitle() << endl;
		cout << "Book Id : " << getBookID() << endl;
		if (getBookStatus()) {
			cout << "Book Status : " << "Available" << endl;
		}
		else {
			cout << "Book Status : " << "Not Available" << endl;
		}
		cout << "Author Name : " << getBookWriter().getAuthorName() << endl;
		cout << "Author Email : " << getBookWriter().getAuthorEmail() << endl;
		cout << "====================================== \n";
	}
};
int Book::idhelper = 0;

class Library {
	string name;
	vector<Book>books;
	vector<Book> ::iterator it;
	static int bookcount;
public:
	Library(string name) {
		this->name = name;
	}
	void AddBook(Book b) {
		books.push_back(b);
		bookcount++;
	}
	void RemoveBook(int id) {
		for (it = books.begin(); it != books.end(); it++) {
			if (it->getBookID() == id) {
				books.erase(it);
				bookcount--;
				cout << "Book Removed Succesfully\n";
				return;
			}
		}
		cout << "Book not found\n";
	}
	void BorrowBook(int id) {
		for (it = books.begin(); it != books.end(); it++) {
			if (it->getBookID() == id) {
				if (it->getBookStatus()) {
					it->setBookStatus(false);
					cout << "Book Borrowed Succesfully\n";
					return;
				}
				else {
					cout << "Book is not available\n";
					return;
				}
			}
		}
		cout << "Book not found\n";
	}
	void ReturnBook(int id) {
		for (it = books.begin(); it != books.end(); it++) {
			if (it->getBookID() == id) {
				it->setBookStatus(true);
				cout << "Book Returned Succesfully\n";
				return;
			}
		}
		cout << "Book not found\n";
	}
	Book* SearchBook(int id) {
		for (it = books.begin(); it != books.end(); it++) {
			if (it->getBookID() == id) {
				return &(*it);
			}
		}
		return nullptr;
	}
	void DisplayAllBooks() {
		for (it = books.begin(); it != books.end(); it++) {
			it->DispalyBook();
		}
	}
};
int Library::bookcount = 0;


void ShowChoices() {
	cout << "1-AddBook" << endl;
	cout << "2-RemoveBook" << endl;
	cout << "3-BorrowBook" << endl;
	cout << "4-ReturnBook" << endl;
	cout << "5-SearchBook" << endl;
	cout << "6-DisplayBooks" << endl;
	cout << "7-LogOut" << endl;
}

int main()
{
	int choice;
	Library l("MyLibrary");
	
	
	bool flag = true;
	while (flag) {
		ShowChoices();
		cout << "\nEnter Your Choice\n";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			string booktitle, writername, writeremail;
			cout << "\nPlease Enter Book Title\n";
			cin >> booktitle;
			cout << "\nPlease Enter Writer Name\n";
			cin >> writername;
			cout << "\nPlease Enter Writer Email\n";
			cin >> writeremail;
			Author a(writername, writeremail);
			Book b(booktitle, a);
			l.AddBook(b);
		}
			break;
		case 2:
			int id;
			cout << "\nPlease Enter Book ID\n";
			cin >> id;
			l.RemoveBook(id);
			break;
		case 3:
			cout << "\nPlease Enter Book ID\n";
			cin >> id;
			l.BorrowBook(id);
			break;
		case 4:
			cout << "\nPlease Enter Book ID\n";
			cin >> id;
			l.ReturnBook(id);
			break;
		case 5:
		{
			cout << "\nPlease Enter Book ID\n";
			cin >> id;
			Book* search = l.SearchBook(id);
			if (search != nullptr) {
				cout << "Book is Founded Successfully\n";
				search->DispalyBook();
			}
			else {
				cout << "Book not fount\n";
			}
		}
			break;
		case 6:
			l.DisplayAllBooks();
			break;
		case 7:
			flag = false;
			break;
		default:
			cout << "please enter valid number\n";
			break;
		}
		system("pause");
		system("cls");
	}
	
	
}