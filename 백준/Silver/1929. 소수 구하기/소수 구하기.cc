#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<int> A(N+1);
    
    for(int i = 2; i <= N; i++){
        A[i] = i;
    }
    // 제곱근까지만 계산
    for(int i = 2; i <= sqrt(N); i++){
        if(A[i] == 0){
            continue;
        }
        // i의 배수만 제거
        for(int j = i * i; j <= N; j += i){
            A[j] = 0;
        }
    }
    for(int i = M; i <= N; i++){
        if(A[i] != 0){
            cout << A[i] << "\n";
        }
    }
}