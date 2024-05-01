#pragma once
#include "Client.h"

class Employee : public Person {
protected:
	Attribute
	double salary;
public:
	Constructors
	Employee() : Person() {
		this->salary = 0.0;
	}
	Employee(string name, int id, string password, double salary) : Person(name, id, password) {
		this->salary = salary;
	}
	Setter
	void setSalary(double salary) {
		this->salary = salary;
	}
	Getter
	double getSalary() {
		return this->salary;
	}
	Methods
	void display() {
		Person::display();
		cout << "Salary: " << this->salary << endl;
	}
	void addClient(Client& client) {
		allClients.push_back(client);
	}
	Client* searchClient(int id) {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id) return clIt._Ptr;
		}
		return NULL;
	}
	void listClient() {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			clIt->display();
			cout << "-------------------------\n";
		}
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
};

static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;