#include <iostream>
#include <cmath>
using namespace std;

int N;
int M[100];

int ShortLength(int j) {

    int sum = 0;

    for(int m = 0; m < N; m++) {
        sum += M[m] * abs(m - j);
    }

    return sum;
}

int main() {
    cin >> N;


    for(int i = 0; i < N; i++) {
        cin >> M[i];
    }

    int answer = ShortLength(0);

    for(int k = 0;  k < N; k++){
        int current = ShortLength(k);
        answer = min(answer, current);
    }

    cout << answer;

    return 0;
}