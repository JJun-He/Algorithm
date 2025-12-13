#include <iostream>
#include <deque>
using namespace std;


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T;
   cin >> T;

   while(T--){
      string p;
      cin >> p;

      int n;
      cin >> n;

      string arr;
      cin >> arr;

      deque<int> deq;
      string num = "";

      for(char c: arr){
         if(isdigit(c)){
            num += c;
         }else{
            if(!num.empty()){
               deq.push_back(stoi(num));
               num.clear();
            }
         }
      }

      bool reversed = false;
      bool error = false;

      for(char cmd: p){
         if(cmd == 'R'){
            reversed = !reversed;
         }else if(cmd == 'D'){
            if(deq.empty()){
               error = true;
               break;
            }
            if(!reversed)
               deq.pop_front();
            else
               deq.pop_back();
         }
      }

      if(error){
         cout << "error\n";
         continue;
      }

      // 출력
      cout << "[";
      if(!deq.empty()){
         if(!reversed){
            for(int i = 0; i < deq.size(); i++){
               cout << deq[i];
               if(i + 1 < deq.size()) cout << ",";
            }
         }
         else{
            for(int i = (int)deq.size() - 1; i >= 0; i--){
               cout << deq[i];
               if(i > 0) cout << ",";
            }
         }
      }
      cout << "]\n";
   }
   return 0;
}