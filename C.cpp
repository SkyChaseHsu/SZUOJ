#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point {
public:
    Point(double x_v = 0, double y_v = 0)
            : x(x_v), y(y_v) {};
    friend double Distance(Point &a, Point &b);
private:
    double x, y;
};

double Distance(Point &a, Point &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
//    freopen("ojdata.txt", "r", stdin);

    int t;
    cin>>t;
    double x_v, y_v;
    while (t--) {
        cin>>x_v>>y_v;
        Point a(x_v, y_v);
        cin>>x_v>>y_v;
        Point b(x_v, y_v);
        cout<<(int) Distance(a, b)<<endl;
    }

    return 0;
}