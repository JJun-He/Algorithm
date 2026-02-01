#include <iostream>
#include <queue>
using namespace std;


// 1 곱하는 로직은 넣지 말기(헷갈리는 부분)
// 1*3보다 1+3이 더 큰법
int main()
{
    int N;
    cin >> N;
    priority_queue<int> pluspq;
    priority_queue<int, vector<int>, greater<int>> minuspq;
    int one = 0;
    int zero = 0;


    for(int i = 0; i < N; i++){
        int data;
        cin >> data;
        
        if(data > 1){
            pluspq.push(data);
        }else if(data == 1){
            one++;
        }else if(data == 0){
            zero++;
        }
        else{
            minuspq.push(data);
        }
    }

    int sum = 0;

    // 양수 처리
    while(pluspq.size() > 1){
        int first = pluspq.top();
        pluspq.pop();
        int second = pluspq.top();
        pluspq.pop();
        sum = sum + first*second;
    }
    if(!pluspq.empty()){
        sum = sum + pluspq.top();
        pluspq.pop();
    }

    // 음수 처리
    while(minuspq.size() > 1){
        int first = minuspq.top();
        minuspq.pop();
        int second = minuspq.top();
        minuspq.pop();
        sum = sum + first * second;
    }
    if(!minuspq.empty()){
        if(zero > 0){
            sum += minuspq.top() * 0;
        } else {
            sum += minuspq.top();
        }
    }

    sum = sum + one;
    cout << sum << endl;

}