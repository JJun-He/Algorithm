#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool broke[10];

// 특정 채널로 갈 수 있는지 확인
bool cango(int channel){
   if(channel == 0){
      return !broke[0];
   }

   while(channel > 0){
      if(broke[channel % 10]){
         return false;
      }
      channel /= 10;
   }

   return true;
}

// 자릿수 확인
int length(int num){
   if(num == 0) return 1;

   int length = 0;
   while(num > 0){
      length++;
      num /= 10;
   }
   return length;
}


int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int N, M;

   cin >> N;
   cin >> M;

   for(int i = 0; i < M; i++){
      int x;
      cin >> x;
      broke[x] = true;
   }

   // +, - 사용
   int press = abs(N - 100);

   // 숫자 버튼으로 사용하는 경우
   for(int i = 0; i <= 999999; i++){
      if(cango(i)){
         int final = length(i) + abs(N - i);
         press = min(press, final);
      }
   }

   cout << press;
   
   return 0;
}