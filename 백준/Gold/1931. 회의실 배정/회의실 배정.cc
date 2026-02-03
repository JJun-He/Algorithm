#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);

    for(int i = 0; i < N; i++){
        cin >> A[i].second;
        cin >> A[i].first;
    }

    sort(A.begin(), A.end());

    int count = 0;

    // end를 -1로 처리하면 깔끔한 이유
    // - 첫 회의 따로 처리 x
    // - 의미 직관적 + 조건이 널널함
    int end = -1;

    for(int i = 0; i < N; i++){
        if(A[i].second >= end){
            end = A[i].first;
            count++;
        }
    }

    cout << count << "\n";
}