#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A;
vector<bool> visited;
void DFS(int v);


int main(){

   int N, M;
   cin >> N >> M;
   A.resize(N+1);
   visited = vector<bool>(N+1, false);

   for(int i = 0; i < M; i++){
      int a, b;
      cin >> a >> b;
      A[a].push_back(b);
      A[b].push_back(a);
   }

   int count = 0;

   for(int i = 1; i <= N; i++){
      if(!visited[i]){
         count++;
         DFS(i);
      }
   }
   cout << count << endl;
}

void DFS(int v){
   if(visited[v]){
      return;
   }

   visited[v] = true;

   for(int i: A[v]){
      if(visited[i] == false){
         DFS(i);
      }
   }
}

