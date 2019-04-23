#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class complex {
public:
    complex (double r_v = 0, double i_v = 0)
            :real(r_v), imag(i_v)
    {};

    friend complex addCom (complex c1, complex c2);
    // 友元函数，复数 c1 + c2 （二参数对象相加）

    friend complex minusCom (complex c1, complex c2);

    friend void outCom (complex c);
    // 友元函数，输出类对象c的有关数据（c为参数对象）

private:
    double real; // 实部
    double imag; // 虚部
};

complex addCom (complex c1, complex c2) {
    return complex (c1.real + c2.real, c1.imag + c2.imag);
}

complex minusCom (complex c1, complex c2) {
    return complex (c1.real - c2.real, c1.imag - c2.imag);
}

void outCom (complex c) {
    cout<<"("<<c.real<<","<<c.imag<<")"<<endl;
}

int main() {
//    freopen("ojdata.txt", "r", stdin);
    int r_v, i_v, t;
    char o;

    cin>>r_v>>i_v;
    complex a(r_v, i_v);

    cin>>t;
    while(t--) {
        cin>>o>>r_v>>i_v;
        complex b(r_v, i_v);
        if (o == '+') {
            a = addCom(a, b);
            outCom(a);
        } else {
            a = minusCom(a, b);
            outCom(a);
        }
    }

    return 0;
}