#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> A;
vector<bool> visited;
void DFS(int a, int depth);
bool arrive;

int main()
{
   int N, M;
   cin >> N >> M;
   A.resize(N);
   visited = vector<bool>(N, false);
   arrive = false;

   for(int i = 0; i < M; i++){
      int c, d;
      cin >> c >> d;
      A[c].push_back(d);
      A[d].push_back(c);
   }
   for(int i = 0; i < N; i++){
      DFS(i, 1);
      if(arrive)
         break;
   }

   if(arrive){
      cout << 1 << "\n";
   }
   else{
      cout << 0 << "\n";
   }
}

void DFS(int a, int depth){
   if(depth == 5 || arrive){
      arrive = true;
      return;
   }
   visited[a] = true;

   for(int i : A[a]){
      if(!visited[i]){
         DFS(i, depth + 1);
      }
   }
   visited[a] = false;
}
