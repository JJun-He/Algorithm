#include <iostream>
#include <vector>

using namespace std;

void DFS(int node);
static vector<vector<int>> A;
static vector<int> check;
static vector<bool> visited;
bool IsEven;


int main() {


    int N;
    cin >> N;

    for (int t = 0; t < N; t++) {
        int B, E;
        cin >> B >> E;
        A.resize(B+1);
        visited.resize(B+1, false);
        check.resize(B+1);
        IsEven = true;

        for (int i = 0; i < E; i++) {
            int D, E;
            cin >> D >> E;
            A[D].push_back(E);
            A[E].push_back(D);
        }

        // 모든 노드에서 수행
        for (int i = 1; i <= B; i++) {
            if (IsEven) {
                DFS(i);
            }
            else {
                break;
            }
        }
        if (IsEven) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
        for (int i = 0; i <= B; i++) {
            A[i].clear();
            visited[i] = false;
            check[i] = 0;
        }
    }
}

void DFS(int node) {

    visited[node] = true;

    for (int i : A[node]) {
        if (!visited[i]) {
            // 인접한 노드는 같은 집합이 아니므로 다른 집합으로 처리
            check[i] = (check[node] + 1) % 2;
            DFS(i);
        }
        else if (check[node] ==  check[i]) {
            // 이미 방문한 노드가 현재 노드의 같은 집합이면 이분 그래프가 아님
            IsEven = false;
        }
    }
}
