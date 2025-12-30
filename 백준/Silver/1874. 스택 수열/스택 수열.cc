#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n, 0);
    vector<char> result;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    stack<int> Stack;
    int num = 1;
    bool result1 = true;

    for(int i = 0; i < A.size(); i++){
        int recent = A[i];
        if(recent >= num){
            while(recent >= num){
                Stack.push(num++);
                result.push_back('+');
            }
            Stack.pop();
            result.push_back('-');
        }
        else{
            int N = Stack.top();
            Stack.pop();
            if(N > recent){
                cout << "NO";
                result1 = false;
                break;
            }
            else{
                result.push_back('-');
            }
        }
    } 
    if(result1){
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << '\n';
        }
    }

}