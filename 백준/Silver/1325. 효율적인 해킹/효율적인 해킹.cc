#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int node);
vector<vector<int>> A;
vector<int> answer;
vector<bool> visited;

int main() {

    long N, M;
    cin >> N >> M;
    A.resize(N+1);
    answer.resize(N+1);

    for (int i = 0; i < M; i++) {
        int B, C;
        cin >> B >> C;
        A[B].push_back(C);
    }

    visited.resize(N+1);

    for (int i = 0; i <= N; i++) {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }

    int max_value = 0;
    
    for (int i = 1; i <= N; i++) {
        max_value = max(max_value, answer[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        if (answer[i] == max_value) {
            cout << i << endl;
        }
    }
}

void BFS(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i : A[now]) {
            if (visited[i] == false) {
                visited[i] = true;
                answer[i]++;
                q.push(i);
            }
        }
    }
}
