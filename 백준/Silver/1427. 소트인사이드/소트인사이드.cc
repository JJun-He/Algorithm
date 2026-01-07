#include <iostream>
#include <vector>
using namespace std;

int main(){

   string N;
   cin >> N;
   vector<int> A(N.size(), 0);

   for(int i = 0; i < N.size(); i++){
      A[i] = N[i] - '0';
   }

   for(int i = 0; i < N.size(); i++){
      int max = i;
      for(int j = i + 1; j < N.size(); j++){
         if(A[j] > A[max])
            max = j;
      }
      if(A[i] < A[max]){
         int temp = A[i];
         A[i] = A[max];
         A[max] = temp;
      }
   }

   for(int i = 0; i < N.size(); i++){
      cout << A[i];
   }
}