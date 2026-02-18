#include <iostream>
#include <vector>

using namespace std;

long gcd(long a, long b);
vector<long> execute(long a, long b);

int main() {
    long a, b, c;
    cin >> a >> b >> c;

    long target = gcd(a, b);

    // 해 존재 여부 검사
    // gcd(a,b) / c => 정수해를 가지 수 있다.
    if (c % target != 0) {
        cout << -1 << "\n";
    }else {
        int m = (int)(c / target);
        vector<long> ret = execute(a, b);
        cout << ret[0] * m << " " << ret[1] * m;
    }
}

vector<long> execute(long a, long b) {
    vector<long> ret(2);

    // 기저 조건
    if (b == 0) {
        ret[0] = 1;
        ret[1] = 0;
        return ret;
    }

    // 몫 구하기
    long q = a/b;

    vector<long> v = execute(b, a % b); // 호제법 수행

    // gcd (a, b) = gcd(b, a %b)
    // bx + (a%b)y = gcd(a, b)
    // a % b = a - qb
    // bx + (a-qb)y = gcd
    // ay + b(x-qy) = gcd
    ret[0] = v[1];
    ret[1] = v[0] - v[1] * q;
    return ret;
}

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

