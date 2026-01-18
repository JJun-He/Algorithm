#include <iostream>
#include <vector>
using namespace std;

int N;
void DFS(int number, int a); // a는 자릿수
bool isPrime(int num);


int main()
{
   cin >> N;
   DFS(2, 1);
   DFS(3, 1);
   DFS(5, 1);
   DFS(7, 1);
}


void DFS(int number, int a){
   if(a == N){
      if(isPrime(number)){
         cout << number << "\n";
      }
      return;
   }
   for(int i = 0; i < 10; i++){
      if(i % 2 == 0){
         continue;
      }
      if(isPrime(number * 10 + i)){
         DFS(number * 10 + i, a + 1);
      }
   }
}

bool isPrime(int num){
   if(num < 2) return false;
   for(int i = 2; i <= num-1;i++){
      if(num % i == 0){
         return false;
      }
   }
   return true;
}