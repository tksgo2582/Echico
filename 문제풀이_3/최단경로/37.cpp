//37 플로이드
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 110
#define INF 1e6

int N, M;
int graph[MAX_N][MAX_N];

void init() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
}
//플로이드, 기존의 경우와 자신을 경유해서 가는것중 어느것이 빠른지 비교 검사
// 각 점들끼리의 최단거리 구할 때 사용.
void floyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] > c)
            graph[a][b] = c;
    }
    floyd();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] == INF)
                cout << 0 << ' ';
            else {
                cout << graph[i][j] << ' ';
            }
        }
        cout << "\n";
    }
}