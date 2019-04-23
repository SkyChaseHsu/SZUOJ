#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Tv;
class Remote;

class Tv {
    friend class Remote;
public:
    Tv(int state_v, int volume_v, int channel_v, int mode_v, int input_v);
    void onoff() {state == 1 ? state = 0 : state = 1;} // 切换电视开关
    bool ison()const {return state == 1 ? true : false;}      // 判断电视开关状态，on 返回 true
    bool volup()    {if(state && volume <= 20) volume++;}
    bool voldown()  {if(state && volume >  0 ) volume--;}
    void chanup()   {if(state && channel <= maxchannel) channel++;}
    void chandown() {if(state && channel >  0         ) channel--;}
    void set_mode() {if(state) mode == 1? mode = 0 : mode = 1;}
    void set_input() {if(state)input == 1? input = 0 : input = 1;}
    void settings()const {
        if (state == 1) cout<<"on ";        else cout<<"off ";
        cout<<volume<<" "<<channel<<" ";
        if (mode == 0)  cout<<"Cable ";     else cout<<"Antenna ";
        if (input == 0)  cout<<"VCR"<<endl;   else cout<<"TV"<<endl;
    }

private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

Tv::Tv(int state_v, int volume_v, int channel_v, int mode_v, int input_v) {
    state = state_v;
    volume = volume_v;
    channel = channel_v;
    mode = mode_v;
    input = input_v;
    maxchannel = 100;
}

class Remote {
private:
    int mode;
public:
    Remote(int m): mode(m) {}
    bool volup(Tv &t) {return t.volup();}
    bool voldown(Tv &t) {return t.voldown();}
    void onoff(Tv &t) {t.onoff();}
    void chanup(Tv &t) {t.chanup();}
    void chandown(Tv &t) {t.chandown();}
    void set_chan(Tv &t, int c) {
        if(t.ison() && c >= 0 && c <= t.maxchannel)
            t.channel = c;
    }
    void set_mode(Tv &t) {t.set_mode();}
    void set_input(Tv &t) {t.set_input();}
};

int main() {
//    freopen("ojdata.txt", "r", stdin);
    string state, mode, input;
    int volume, channel;

    cin >> state >> volume >> channel >> mode >> input;
    int state_v = state == "on" ?    1 : 0;
    int mode_v  = mode  == "Cable" ? 0 : 1;
    int input_v = input == "VCR" ?   0 : 1;

    Tv tv(state_v, volume, channel, mode_v, input_v);
    Remote re(mode_v);

    string oper;
    while (cin>>oper) {
        if (oper.compare("onoff") == 0)    {re.onoff(tv); continue;}
        if (oper.compare("volup") == 0)    {re.volup(tv); continue;}
        if (oper.compare("voldown") == 0)  {re.voldown(tv); continue;}
        if (oper.compare("chanup") == 0)   {re.chanup(tv); continue;}
        if (oper.compare("chandown") == 0) {re.chandown(tv);continue;}
        if (oper.compare("set_mode") == 0) {re.set_mode(tv);continue;}
        if (oper.compare("set_input") == 0){re.set_input(tv);continue;}
        if (oper.compare("set_chan") == 0) {
            int c;
            cin>>c;
            re.set_chan(tv, c);
            continue;
        }
    }

    tv.settings();

    return 0;
}