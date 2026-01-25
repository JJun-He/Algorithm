#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    vector<int> A(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    cin >> M;

    for(int i = 0; i < M; i++){
        bool find = false;
        int a;
        cin >> a;

        int start = 0;
        int end = A.size() - 1;

        while(start <= end){
            int mid_index = (start + end) / 2;
            int mid_value = A[mid_index];

            if(mid_value > a){
                end = mid_index - 1;
            }else if(mid_value < a){
                start = mid_index + 1;
            }
            else{
                find = true;
                break;
            }
        }
        
        if(find){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }

}