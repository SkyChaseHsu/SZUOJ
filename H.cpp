#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Tv;
class Remote;

class Tv {
public:
    Tv(int s, int mc);
    void onoff();
    bool ison()const;
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode();
    void set_input();
    void settings()const;
    friend class Remote;

private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

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
    void set_chan(Tv &t, int c) {t.channel = c;}
    void set_mode(Tv &t) {t.set_mode();
    void set_input(Tv &t) {t.set_input();}
};

int main() {
//    freopen("ojdata.txt", "r", stdin);

    return 0;
}