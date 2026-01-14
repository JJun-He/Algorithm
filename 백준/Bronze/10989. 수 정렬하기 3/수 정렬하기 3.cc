#include <iostream>
#include <vector>
using namespace std;

int main(){

   int N;
   cin >> N;
   
   int count[10001] = {0};
   int num = 0;

   for(int i = 0; i < N; i++){
      cin >> num;
      count[num]++;
   }
   for(int i = 0; i <= 10000; i++){
      if(count[i] != 0){
         for(int j = 0; j < count[i]; j++){
            cout << i << "\n";
         }
      }
   }

}

