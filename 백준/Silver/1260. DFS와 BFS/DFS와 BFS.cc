#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> A;
vector<bool> visited;
bool arrive;
void Dfs(int x);
void Bfs(int y);

int main(){
   int N, M, start;
   cin >> N >> M >> start;
   arrive = false;
   A.resize(N+1);

   for(int i = 0; i < M; i++){
      int a, b;
      cin >> a >> b;
      A[a].push_back(b);
      A[b].push_back(a);
   }

   for(int i = 1; i <= N; i++){
      sort(A[i].begin(), A[i].end());
   }

   visited = vector<bool>(N+1, false);
   Dfs(start);
   fill(visited.begin(), visited.end(), false);
   Bfs(start);
}

void Dfs(int x){
   cout << x << endl;
   
   visited[x] = true;

   for(int i : A[x]){
      if(!visited[i])
         Dfs(i);
   }
}

void Bfs(int x){
   queue<int> mq;
   mq.push(x);
   visited[x] = true;

   while(!mq.empty()){
      int cx = mq.front();
      mq.pop();
      cout << cx << endl;
      for(int i : A[cx]){
         if(!visited[i]){
            visited[i] = true;
            mq.push(i);
         }
      }

   }
}