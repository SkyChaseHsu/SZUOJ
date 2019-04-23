#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Date;
class Time;

class Date {
private:
    int year, month, day;
public:
    Date(int y_v = 0, int m_v = 0, int d_v = 0)
        :year(y_v), month(m_v),day(d_v){}
    friend void Display(Date &date, Time &time);
};

class Time {
//    friend class Date;
private:
    int hour, minute, second;
public:
    Time(int h_v = 0, int m_v = 0, int s_v = 0)
        :hour(h_v), minute(m_v), second(s_v){}
    friend void Display(Date &date, Time &time);

};

void Display (Date &date, Time &time) {
    cout<<date.year<<"-"<<setfill('0')<<setw(2)<<date.month<<"-";
    cout<<setfill('0')<<setw(2)<<date.day<<" ";
    cout<<setfill('0')<<setw(2)<<time.hour<<":";
    cout<<setfill('0')<<setw(2)<<time.minute<<":";
    cout<<setfill('0')<<setw(2)<<time.second<<endl;
}
int main() {
//    freopen("ojdata.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        int y_v, m_v, d_v, h_v, mi_v, s_v;
        cin>>y_v>>m_v>>d_v>>h_v>>mi_v>>s_v;
        Date date(y_v, m_v, d_v);
        Time time(h_v, mi_v, s_v);
        Display(date, time);
    }
    return 0;
}