#include <iostream>
#include <string.h>
using namespace std;

class Customer {
public:
    Customer (char * name);
    ~Customer ();
    static void changeYear (int r);
    void Display();
private:
    static int TotalCusNum;
    static int Rent;
    static int Year;
    int CustID;
    char * custName;
};

Customer::Customer(char *name) {
    custName = new char[20];
    strcpy(custName , name);
    TotalCusNum += 1;
    CustID = Year * 10000 + TotalCusNum;
}

Customer::~Customer() {
    delete []custName;
}

void Customer::changeYear(int r) {
    Year = r;
}

void Customer::Display() {
    cout<<custName<<" "<<CustID<<" "<<TotalCusNum<<" "<< TotalCusNum * Rent<<endl;
}

int Customer::TotalCusNum = 0;
int Customer::Rent = 150;
int Customer::Year = 2014;

int main() {
    int t, year;
    char * name = new char[20];
    cin>>t;

    while (t--) {
        cin>>year;
        Customer::changeYear(year);
        while (true) {
            cin>>name;
            if (!strcmp(name, "0")) break;
            Customer cus(name);
            cus.Display();
        }
    }

    delete []name;

    return 0;
}