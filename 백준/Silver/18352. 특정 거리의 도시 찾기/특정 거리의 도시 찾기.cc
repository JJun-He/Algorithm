#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS(int node);
vector<vector<int>> A;
vector<int> visited;
vector<int> answer;

int main() {
    long N, M, K, X;
    cin >> N >> M >> K >> X; // 노드 수, 에지 수, 목표 거리, 시작점
    A.resize(N+1);

    // B -> C 방향으로만 연결
    for (int i = 0; i < M; i++) {
        int B, C;
        cin >> B >> C;
        A[B].push_back(C);
    }

    // 방문 초기화
    visited.resize(N+1);

    for (int i = 0; i <= N; i++) {
        visited[i] = -1;
    }

    // BFS 시작
    BFS(X);

    for (int i = 0; i <= N; i++) {
        if (visited[i] == K) {
            answer.push_back(i);
        }
    }
    if (answer.empty()) {
        cout << -1 << "\n";
    }
    else {
        sort(answer.begin(), answer.end());
        for (int temp: answer) {
            cout << temp << "\n";
        }
    }
}

void BFS(int node) {
    queue<int> queue;
    queue.push(node);
    // 시작점 거리 설정(0으로)
    visited[node] = 0;

    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        for (int i : A[now]) {
            if (visited[i] == -1) {
                visited[i] = visited[now] + 1;
                queue.push(i);
            }
        }
    }
}
