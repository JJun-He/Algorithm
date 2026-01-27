#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> A;
vector<bool> visited;
vector<int> dist;
void BFS(int node);

int main()
{
    int N;
    cin >> N;
    A.resize(N+1);

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        while(true){
            int b,c;
            cin >> b;
            if(b == -1){
                break;
            }
            cin >> c;
            A[a].push_back(edge(b, c));
        }
    }

    dist = vector<int>(N+1, 0);
    visited = vector<bool>(N+1, false);
    BFS(1);
    int Max = 1;

    for(int i = 2; i <= N; i++){
        if(dist[Max] < dist[i]){
            Max = i;
        }
    }
    fill(dist.begin(), dist.end(), 0);
    fill(visited.begin(), visited.end(), false);
    BFS(Max);
    sort(dist.begin(), dist.end());
    cout << dist[N] << endl;
}

void BFS(int index){
    queue<int> mq;
    mq.push(index);
    visited[index] = true;

    while(!mq.empty()){
        int now = mq.front();
        mq.pop();
        for(edge i : A[now]){
            if(!visited[i.first]){
                visited[i.first] = true;
                mq.push(i.first);
                dist[i.first] = dist[now] + i.second;
            }
        }
    }
}