#include <iostream>
#include <vector>
using namespace std;

int main(){
   int N;
   cin >> N;

   vector<int> A(N, 0);
   vector<int> B(N, 0);

   for(int i = 0; i < N; i++){
      cin >> A[i];
   }

   for(int i = 0; i < N; i++){
      int c = i;
      int c_value = A[i];
      for(int j = i - 1; j >= 0; j--){
         if(A[j] < A[i]){
            c = j+1;
            break;
         }
         if(j == 0){
            c = 0;
         }
      }
      for(int j = i; j > c; j--){
         A[j] = A[j-1];
      }
      A[c] = c_value;
   }

   B[0] = A[0];
   for(int i = 1; i < N; i++){
      B[i] = B[i-1] + A[i];
   }

   int sum = 0;

   for(int i = 0; i < N; i++){
      sum = sum + B[i];
   }

   cout << sum;
}