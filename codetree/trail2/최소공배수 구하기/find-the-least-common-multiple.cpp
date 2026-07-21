#include <iostream>

using namespace std;

int n, m, k, s;

int GCD(int n, int m) {

    while(m != 0) {
        int k = n % m;
        n = m;
        m = k;
    }


    return n;
}

int main() {
    cin >> n >> m;

    int s = GCD(n, m);


    int k = n/s*m;
    cout << k;
}