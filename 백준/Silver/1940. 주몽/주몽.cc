#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int main(){

   int N, M;
   cin >> N >> M;
   vector<int> A(N, 0);
   int count = 0;

   for(int i = 0; i < N; i++){
      cin >> A[i];
   }

   sort(A.begin(), A.end());

   int i = 0;
   int j = N - 1;
   while(i < j){
      if(A[i] +  A[j] < M)
         i++;
      else if(A[i] + A[j] > M)
         j--;
      else if(A[i] + A[j] == M){
         count++;
         i++;
         j--;
      }
   }

   cout << count;

}