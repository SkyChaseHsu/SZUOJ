#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account {
public:
    Account();
    Account (string accno_v, string name_v, float balance_v);
    ~Account() {};
    void deposit (float amount)     {balance += amount;}
    void withdraw (float amount)    {balance -= amount;tol_balance += balance;}
    float getBalance()              {return balance;   }
    static int getCount()           {return count;     }
    static float getInterest()      {return interest;  }
    static void setInterset(float interest_v) {interest = interest_v;}
    friend void update (Account &a);
    void show();
    void setAcc (string accno_v, string name_v, float balance_v);
    static float getTol() {return tol_balance;}
private:
    static int count;       // 银行账户数量
    static float interest;  // 利率
    static float tol_balance;
    string accno, name;     // 账户与户名
    float balance;          // 余额
};

int Account::count = 0;
float Account::tol_balance = 0;

Account::Account (string accno_v, string name_v, float balance_v) {
    accno = accno_v;
    name = name_v;
    balance = balance_v;
    count++;
}

Account::Account() {
    accno = "0";
    name = "default";
    balance = 0;
    count++;
}

void Account::setAcc (string accno_v, string name_v, float balance_v) {
    accno = accno_v;
    name = name_v;
    balance = balance_v;
}

void update (Account &a) {
    a.balance = a.balance * (1 + Account::getInterest());
}

void Account::show() {
    cout<<accno<<" "<<name<<" ";
}

float Account::interest = 0;

int main() {
//    freopen("ojdata.txt", "r", stdin);
    float interest_v;
    int t;
    int balance_v, de_v, wi_v;
    string accno_v, name_v;

    cin>>interest_v;
    Account::setInterset(interest_v);

    cin>>t;
    Account * a = new Account[t];

    for (int i = 0; i < t; i++) {
        cin>>accno_v>>name_v>>balance_v>>de_v>>wi_v;
        a[i].setAcc(accno_v, name_v, balance_v);
        a[i].show();
        a[i].deposit(de_v);
        cout<<a[i].getBalance()<<" ";
        update(a[i]);
        cout<<a[i].getBalance()<<" ";
        a[i].withdraw(wi_v);
        cout<<a[i].getBalance()<<endl;
    }
    cout<<Account::getTol()<<endl;
    delete []a;
    return 0;
}