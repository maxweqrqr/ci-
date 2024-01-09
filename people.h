#include <iostream>
#include <string>
using namespace std;

class client {
private:
	string name, surname, number,company;
public:
	string getName() {
		return name;
	}
	string getSurname() {
		return surname;
	}
	string getNumber() {
		return number;
	}
	string getCompany() {
		return company;
	}
	client() {
		name = "Ваня";
		surname = "Иванов";
		number = "88005553535";
		company = "OOO";
	}
	client(string name, string surname, string number,string company) {
		this->name = name;
		this->surname = surname;
		this->number = number;
		this->company = company;
	}
	void print() {
		cout << surname << " " << name << " - " << number <<" "<<company<< endl;;
	}
};
