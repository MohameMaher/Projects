#pragma once
#include "Person.h"
class Client : public Person {
private:
	
	double balance;
public:
	
	Client() : Person() {
		this->balance = 0.0;
	}
	Client(string name, int id, string password, double balance) : Person(name, id, password) {
		setBalance(balance);
	}
	
	void setBalance(double balance) {
	
			if (Validation::ValidateBalance(balance)) {
				this->balance = balance;
				
			}
			else {

				cout << "Very low balance" << endl;
				
			}
		
	}
	
	double getBalance() {
		return this->balance;
	}
	
	void display() {
		Person::display();
		cout << "Balance: " << this->balance << endl;
	}
	void deposit(double amount) {
		this->balance += amount;
		cout << "\nSuccessful transaction.\n";
	}
	void withdraw(double amount) {
		if (amount <= this->balance) {
			this->balance -= amount;
			cout << "\nSuccessful transaction.\n";
		}
		else cout << "\nAmount Exceeded.\n";
	}
	void transferTo(double amount, Client& recipient) {

		if (amount <= balance) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << "\nSuccessful transaction.\n";
		}
		else cout << "\nAmount Exceeded.\n";
	}
	void checkBalance() {
		cout << "Balance: " << this->balance << endl;
	}
};
