#include <iostream>

using namespace std;

int GCD(int n, int m) {

    while(n != 0){
        int k = m % n;
        m = n;
        n = k;
    }

    return m;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << GCD(n, m);
    return 0;
}