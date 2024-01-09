#include <iostream>
#include <string>
#include <stdlib.h>
#include "people.h"
#include <time.h>
using namespace std;

class record {
private:
    string type_object[4] = {
        "Кольца",
        "Браслеты",
        "Сережки",
        "Цепочки"
    };
    string object;
    int number;
    int amount;
    client cl;
    
public:
    record() {
        object = "Кольца";
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
        cout << "Товар: " << object << "; Количество партий: " << amount << ". Количество в одной партии: " <<number<<endl;
    }
    void change() {
        cout << "Выберите пункт заказа, который вы хотели бы отредактировать:\n";
        cout << "1 - Товар\n";
        cout << "2 - Количество партий\n";
        cout << "3 - Количество штук товара в одной парти\n";
        cout << "4 - Информацию о клиенте\n";
        int choose = 0;
        while (choose < 1 || choose>4){
            cin >> choose;
        }
        switch (choose){
        case 1:
            {
            cout << "Выберите тип товара:" << endl;
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
            cout << "Укажите количество партий товара: ";
            cin >> amount;
            break;
        }
        case 3:
        {
            int select = 0;
            cout << "Укажите количество штук товара в одной партии:" << endl;
            do
            {
                cin >> number;

            } while (number < 1);
            
            break;
        }
        case 4:
        {
            string name, surname, number, company;
            cout << "Укажите имя нового клиента: ";
            cin >> name;
            cout << "Укажите фамилию нового клиента: ";
            cin >> name;
            cout << "Укажите номер телефона нового клиента для дальнейшей связи: ";
            cin >> number;
            cout << "Укажите компанию заказчика, если она есть (- если нет)";
            cin >> company;
            cl = client(name, surname, number,company);
            break;
        }
        default:
            break;
        }
    }
};