#include <bits/stdc++.h>
using namespace std;

int N, K, S, X, Y;
int mat[201][201];
vector<pair<int, int>> v[1001];  // 바이러스에 대한 그래프벡터
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<tuple<int, int, int>> q;  //(바이러스, x,y)
    for (int i = 1; i <= K; i++) {  //각 바이러스 번호에 대한 좌표값들
        if (!v[i].empty()) {
            for (auto p : v[i]) {              // q에 현재 있는 바이러스 순서대로 넣어준다.
                q.push({i, p.first, p.second});  //(바이러스번호, x,y)
            }
        }
    }

    while (!q.empty() && S--) {  // 바이러스 들이 존재, 시간증가
        int qs = q.size();       // 현재 q의 사이즈 갱신(현재 시간에 있는 바이러스 개수만큼)
        while (qs--) {            // 그 시간대에 있던 바이러스들 run
            int num, x, y;
            tie(num, x, y) = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (mat[nx][ny] == 0) {
                        mat[nx][ny] = num;
                        q.push({num, nx, ny});
                    }
                }
            }
        }
    }
    cout << mat[X - 1][Y - 1];
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
            if (mat[i][j]) {            // 빈방이 아니라면
                v[mat[i][j]].push_back({i, j}); // 바이러스 벡터그래프 생성
            }
        }
    }
    cin >> S >> X >> Y;
    bfs();
}