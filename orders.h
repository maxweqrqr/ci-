#include <iostream>
#include <string>
#include "record.h"
#include <vector>
#include <fstream>

using namespace std;

class fabrika {
private:
    int n;
    record* orders;
    string type_object[4] = {
        "������",
        "��������",
        "�������",
        "�������"
    };
public:
    fabrika() {
        n = 2;
        setlocale(LC_ALL, "ru");
        orders = new record[n];
        for (int j = 0; j < n; j++) {
            string object,name,surname,number,company;
            int amount= 0, numb = 0;
            float S;

            cout << "�������� ��� ������:" << endl;
            int select = 0;
            for (int i = 0; i < 4; i++) {
                cout << "[" << i + 1 << "] " << type_object[i] << endl;
            }
            while (select < 1 || select>4) {
                cin >> select;
            }
            object = type_object[select - 1];


            cout << "������� ���������� ������ ������: ";
            while (amount<1)
            {
                cin >> amount;
            }
            

            
            cout << "������� ���������� ���� ������ � ����� ������: ";
            while (numb < 1) {
                cin >> numb;
            }

            cout << "������� ���� ���: ";
            cin >> name;
            cout << "������� ���� �������: ";
            cin >> surname;
            cout << "������� ��� ����� �������� ��� ���������� �����: ";
            cin >> number;
            cout << "������� ���� ��������. ���� ���, ��������� '-':";
            cin >> company;
            orders[j] = record(name,surname, number,company, object, amount, numb);

        }
    }
    void print() {
        setlocale(LC_ALL, "ru");
        for (int i = 0; i < n; i++) {
            record current_record = orders[i];
            cout << "[" << i + 1 << "] ";
            current_record.print();
        }
    }
    void addRc() {
        string object, name, surname, number, company;
        int amount, numb = 0;
        float S;

        cout << "�������� ��� ������:" << endl;
        int select = 0;
        for (int i = 0; i < 4; i++) {
            cout << "[" << i + 1 << "] " << type_object[i] << endl;
        }
        while (select < 1 || select>4) {
            cin >> select;
        }
        object = type_object[select - 1];


        cout << "������� ���������� ������ ������: ";
        cin >> amount;



        cout << "������� ���������� ���� ������ � ����� ������:" << endl;
        while (numb < 1) {
            cin >> numb;
        }

        cout << "������� ���� ���: ";
        cin >> name;
        cout << "������� ���� �������: ";
        cin >> surname;
        cout << "������� ��� ����� �������� ��� ���������� �����: ";
        cin >> number;
        cout << "������� ���� ��������. ���� ���, ��������� '-': ";
        cin >> company;
        record newrc(name, surname, number,company, object, amount, numb);
        record* newor = new record[n + 1];
        for (int i = 0; i < n; i++) {
            newor[i] = orders[i];
        }
        newor[n] = newrc;
        n++;
        orders = newor;
    }
    void addRcFile(record &newrc) {
        record* newor = new record[n + 1];
        for (int i = 0; i < n; i++) {
            newor[i] = orders[i];
        }
        newor[n] = newrc;
        n++;
        orders = newor;
    }
    void deleteRc(int k) {
        record* newor = new record[n - 1];
        for (int i = 0,j=0; i < n; i++,j++) {
            if (i == (k - 1))i++;
            if (i<n)newor[j] = orders[i];
        }
        n--;
        orders = newor;
    }
    void saveToFile(bool app) {
        ofstream out;
        try {
            if (app)
                out.open("orders.txt", ios::app);
            else out.open("orders.txt");
        }
        catch (const char* error_message) {
            cout << error_message << endl;
            return;
        }
        if (out.is_open())
        {
            string rcInfo;
            for (int i = 0; i < n; i++) {
                record cr_rc = orders[i];
                rcInfo = cr_rc.getClient().getName() + "||" + cr_rc.getClient().getSurname() + "||" + cr_rc.getClient().getNumber() + "||" + cr_rc.getClient().getCompany() + "||" + cr_rc.getObject() + "||" + to_string(cr_rc.getAmount()) + "||" + to_string(cr_rc.getNumber());
                out << rcInfo << endl;
            }
            out.close();
        }
    }
    void loadFile() {
        ifstream in("orders.txt");
        if (in.is_open())
        {
            string newrc;
            while (getline(in, newrc)) {
                // ����� ������ �� �����
                string name = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string surname = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string number = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string company = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string object = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                int amount = stoi(newrc.substr(0, newrc.find("||")));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                int numb = stoi(newrc.substr(0, newrc.length()));
                record* newrc = new record(name,surname, number,company, object, amount, numb);
                addRcFile(*newrc);
            }
        }
        in.close();
    }
    void changeRecord(int n) {
        orders[n - 1].change();
    }
    int getN() {
        return n;
    }
};