#include <iostream>
#include <deque>
using namespace std;

// STL Deque를 사용
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    
    while (dq.size() > 1) {
        dq.pop_front();  // 맨 위 카드 버리기
        
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);  // 그 다음 카드를 맨 아래로
    }
    
    cout << dq.front() << endl;
    return 0;
}