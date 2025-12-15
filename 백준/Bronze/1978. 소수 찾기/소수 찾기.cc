#include <iostream>

using namespace std;

bool isPrime(int n){
   if(n < 2) return false;
   for(int i = 2; i < n; i++){
      if(n % i == 0)
         return false;
   }
   return true;
}

int main()
{
   int N;
   cin >> N;

   int count = 0;

   for(int i = 0; i < N; i++){
      int x;
      cin >> x;

      if(isPrime(x)){
         count++;
      }
   }

   cout << count;
   return 0;
}