#pragma once
#include "Validation.h"
class Person {
protected:
	string name;
	int id;
	string password;
public:

	Person() {
		this->name = " ";
		this->id = 0;
		this->password = " ";
	}
	Person(string name, int id, string password) {
	
		setName(name);
		setPassword(password);
		setId(id);
	}
	void setName(string name) {
		
			if (Validation::ValidateName(name)) {

				this->name = name;
			
			}
			else {
				cout << "Invalid name" << endl;
				
			}
		
	}
	void setId(int id) {
		this->id = id;
	}
	void setPassword(string password) {
		
			if (Validation::ValidatePassword(password)) {
				this->password = password;
				
			}
			else {
				cout << "Invalid Password" << endl;
			

			}

		
	}
	
	string getName() {
		return this->name;
	}
	int getId() {
		return this->id;
	}
	string getPassword() {
		return this->password;
	}
	
	void display() {
		cout << "Name: " << this->name << endl;
		cout << "Id: " << this->id << endl;
	
	}
};