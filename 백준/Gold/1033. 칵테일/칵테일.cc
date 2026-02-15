#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// tuple: 타입이 다른 값들을 한꺼번에 묶는 컨테이너(장점: 3가지 정보를 한번에 담을 수 있어 굳이 struct 필요 x)
// 현재 노드 : next 노드 = p : q
vector<tuple<int, int, int>> A[10];

// 정수로 만들기 위한 초기 공통 배수
long lcm;
bool visited[10];

// 노드의 실제 계산 값
long D[10];
long gcd(long a, long b);
void DFS(int node);

int main() {
    int N;
    cin >> N;
    lcm = 1;

    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_tuple(b, p ,q));
        A[b].push_back(make_tuple(a, q, p));
        lcm *= (p * q / gcd(p, q));
    }

    D[0] = lcm;
    DFS(0);
    long md = D[0];

    // 모든 값들의 최대공약수를 구함
    for (int i = 1; i < N; i++) {
        md = gcd(md, D[i]);
    }

    // 최소 정수 비율로 출력
    for (int i = 0; i < N; i++) {
        cout << D[i] / md << endl;
    }
}

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }else {
        return gcd(b, a % b);
    }
}

void DFS(int node) {
    visited[node] = true;

    for (tuple<int, int, int> i : A[node]) {
        int next = get<0>(i);
        if (!visited[next]) {
            // node : next = p : q
            D[next] = D[node] * get<2>(i) / get<1>(i);
            DFS(next);
        }
    }
}
