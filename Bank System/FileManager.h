#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface{
private:
	
	 void addClient(Client client) {
		FilesHelper::saveClient(client);
	}
	 void addEmployee(Employee employee) {
		FilesHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", employee);
	}
	 void addAdmin(Admin admin) {
		FilesHelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
	}
	 void getAllClients() {
		FilesHelper::getClients();
	}
	 void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	 void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
	}
	 void removeAllEmployees() {
		FilesHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
	}
	 void removeAllAdmins() {
		FilesHelper::clearFile("Admins.txt", "AdminLastId.txt");
	}
public:
	
	static void getAllData() {
		FileManager f;
		f.getAllClients();
		f.getAllEmployees();
		f.getAllAdmins();
	}
	static void updateClients() {
		FileManager f;
		f.removeAllClients();
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) f.addClient(*clIt);
	}
	static void updateEmployees() {
		FileManager f;
		f.removeAllEmployees();
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) f.addEmployee(*eIt);
	}
	static void updateAdmins() {
		FileManager f;
		f.removeAllAdmins();
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) f.addAdmin(*aIt);
	}
};