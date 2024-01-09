#include <iostream>
#include <string>
#include <stdlib.h>
#include "people.h"
#include <time.h>
using namespace std;

class record {
private:
    string type_object[4] = {
        "������",
        "��������",
        "�������",
        "�������"
    };
    string object;
    int number;
    int amount;
    client cl;
    
public:
    record() {
        object = "������";
        amount = 10;
        number = 100;
    }
    record(string name, string surname, string number, string company, string object,int amount,int numb) {
        this->cl = *(new client(name, surname, number,company));
        this->object = object;
        this->amount = amount;
        this->number = numb;
    }
    string getObject() {
        return object;
    }
    int getAmount() {
        return amount;
    }
    int getNumber() {
        return number;
    }
    client getClient() {
        return cl;
    }
    string getClientInfo() {
        cl.print();
    }
    void print() {
        cl.print();
        cout << "�����: " << object << "; ���������� ������: " << amount << ". ���������� � ����� ������: " <<number<<endl;
    }
    void change() {
        cout << "�������� ����� ������, ������� �� ������ �� ���������������:\n";
        cout << "1 - �����\n";
        cout << "2 - ���������� ������\n";
        cout << "3 - ���������� ���� ������ � ����� �����\n";
        cout << "4 - ���������� � �������\n";
        int choose = 0;
        while (choose < 1 || choose>4){
            cin >> choose;
        }
        switch (choose){
        case 1:
            {
            cout << "�������� ��� ������:" << endl;
            int select = 0;
            for (int i = 0; i < 4; i++) {
                cout << "[" << i + 1 << "] " << type_object[i] << endl;
            }
            while (select < 1 || select>4) {
                cin >> select;
            }
            object = type_object[select - 1];
            break;}
        case 2:
        {
            cout << "������� ���������� ������ ������: ";
            cin >> amount;
            break;
        }
        case 3:
        {
            int select = 0;
            cout << "������� ���������� ���� ������ � ����� ������:" << endl;
            do
            {
                cin >> number;

            } while (number < 1);
            
            break;
        }
        case 4:
        {
            string name, surname, number, company;
            cout << "������� ��� ������ �������: ";
            cin >> name;
            cout << "������� ������� ������ �������: ";
            cin >> name;
            cout << "������� ����� �������� ������ ������� ��� ���������� �����: ";
            cin >> number;
            cout << "������� �������� ���������, ���� ��� ���� (- ���� ���)";
            cin >> company;
            cl = client(name, surname, number,company);
            break;
        }
        default:
            break;
        }
    }
};