//화성탐사
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 130
#define INF 1e9

int T, N;
int mat[MAX_N][MAX_N];
int dijk[MAX_N][MAX_N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-mat[0][0], {0, 0}});
    dijk[0][0] = mat[0][0];

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (dijk[x][y] < dist) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            int new_dist = dist + mat[nx][ny];
            if (new_dist < dijk[nx][ny]) {
                dijk[nx][ny] = new_dist;
                pq.push({-new_dist, {nx, ny}});
            }
        }
    }
}
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dijk[i][j] = INF;
        }
    }
}
int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mat[i][j];
            }
        }
        init();
        dijkstra();
        cout << dijk[N - 1][N - 1] << '\n';
    }
}