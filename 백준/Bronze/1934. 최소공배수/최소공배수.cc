#include <iostream>
using namespace std;

int min(int a, int b);

int main()
{
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int a,b;
        cin >> a >> b;
        int result = a * b / min(a, b);
        cout << result << "\n";
    }
}

int min(int a, int b){
    if(b == 0){
        return a;
    }else{
        return min(b, a % b);
    }
}