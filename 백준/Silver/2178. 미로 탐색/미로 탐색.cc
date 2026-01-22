#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int A[101][101];
bool visited[101][101] = {false};
void BFS(int i, int j);
int N, M;

int main()
{
   
   cin >> N >> M;

  
   for(int i = 0; i < N; i++){
      string s;
      cin >> s;
      for(int j = 0; j < M; j++){
         A[i][j] = s[j] - '0';
      }
   }
   BFS(0,0);
   cout << A[N-1][M-1] << endl;

}

void BFS(int i, int j){
   queue<pair<int, int>> mq;
   mq.push(make_pair(i, j));
   visited[i][j]=true;

   while(!mq.empty()){
      int now[2];
      now[0] = mq.front().first;
      now[1] = mq.front().second;
      mq.pop();
      visited[now[0]][now[1]] = true;

      for(int k = 0; k < 4; k++){
         int x = now[0] + dx[k];
         int y = now[1] + dy[k];

         if (x >= 0 && y >= 0 && x < N && y < M){
            if(A[x][y] !=  0 && !visited[x][y]){
               visited[x][y] = true;
               A[x][y] = A[now[0]][now[1]] + 1;
               mq.push(make_pair(x, y));
            }
         }
      }
   }
}