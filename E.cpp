#include <iostream>
#include <iomanip>
using namespace std;

class CSieve {
private:
    int *p_sieve;
    unsigned long n; // n_v 是最大范围
public:
    CSieve (unsigned long n_v);
    ~CSieve ();
    void printPrime ();
};

CSieve::CSieve(unsigned long n_v) {
    n = n_v;
    p_sieve = new int[n+1];
    for (int i = 2; i <= n; i++) p_sieve[i] = 1;
    p_sieve[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (p_sieve[i]) {
            for (int j = 2; i * j <= n; j++)
                p_sieve[i*j] = 0;
        }
    }
}

CSieve::~CSieve() {
    delete []p_sieve;
}

void CSieve::printPrime() {
    int firstFlag = 0;
    for (int i = 1; i < n; i++) {
        if (p_sieve[i]) {
            if (firstFlag != 0) cout<<" "<<i;
            else                cout<<i;
            firstFlag++;
        }
    }
    if (firstFlag)  cout<<endl;
}

int main() {
//    freopen("ojdata.txt", "r", stdin);
    int t;
    unsigned long n = 0;
    cin>>t;

    while (t--) {
        cin>>n;
        if (n <= 2) continue;
        CSieve cs(n);
        cs.printPrime();
    }

    return 0;
}