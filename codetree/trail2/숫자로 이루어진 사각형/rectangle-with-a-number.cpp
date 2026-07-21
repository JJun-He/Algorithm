#include <iostream>
using namespace std;

void PrintSquare(int n){

    int sum = 0;

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            sum += 1;
            if(sum > 9){
                sum = sum - 9;
            }
            cout << sum << " ";
        }

        cout << "\n";
    }
}

int main() {
    
    int N;
    cin >> N;

    PrintSquare(N);

    return 0;
}