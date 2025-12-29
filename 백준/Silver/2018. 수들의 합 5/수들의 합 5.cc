#include <iostream>
using namespace std;

int main() {

   int N;
   cin >> N;

   int start = 1, end = 1;
   int sum = 1;
   int count = 1;   

   while(end != N){
      if(sum == N){
         count++;
         end++;
         sum += end;
      }
      else if(sum < N){
         end++;
         sum += end;
      }
      else{ 
         sum -= start;
         start++;
      }
   }

   cout << count;
}