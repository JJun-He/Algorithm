#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int a, int b);
vector<int> A;
vector<int> tmp;
long result;

int main(){

   int N;
   cin >> N;
   A.resize(N+1);
   tmp.resize(N+1);

   for(int i = 1; i <= N; i++){
      cin >> A[i];
   }

  
   result = 0;
   merge_sort(1, N);
   cout << result << "\n";
}

void merge_sort(int a, int b){
   if(b - a < 1){
      return;
   }
     
   int m = a + (b-a) / 2;
   merge_sort(a, m);
   merge_sort(m+1, b);

   for(int i = a; i <= b; i++){
      tmp[i] = A[i];
   }

   int k = a;
   int index1 = a;
   int index2 = m+1;

   while(index1 <= m && index2 <= b){
      if(tmp[index1] > tmp[index2]){
         A[k] = tmp[index2];
         result = result + index2 - k;
         k++;
         index2++;
      }
      else{
         A[k] = tmp[index1];
         k++;
         index1++;
      }
   }
   while(index1 <= m){
      A[k] = tmp[index1];
      k++;
      index1++;
   }
   while(index2 <= b){
      A[k] = tmp[index2];
      k++;
      index2++;
   }

}