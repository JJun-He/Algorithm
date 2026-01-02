#include <iostream>
#include <queue>
using namespace std;


struct compare {
   bool operator()(int a, int b){
      int abs_a = abs(a);
      int abs_b = abs(b);
      if(abs_a == abs_b){
         return a > b;
      }else{
         return abs_a > abs_b;
      }
   }
};


int main(){
   priority_queue<int, vector<int>, compare> Aqueue;

   int N;
   cin >> N;

   for(int i = 0; i < N; i++){
      int x;
      cin >> x;

      if(x == 0){
         if(Aqueue.empty()){
            cout << "0\n";
         }else{
            cout << Aqueue.top() << '\n';
            Aqueue.pop();
         }
      }else{
         Aqueue.push(x);
      }

     
   }
}