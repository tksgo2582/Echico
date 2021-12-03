//16 연구소
#include <bits/stdc++.h>
using namespace std;
#define MAX_NM 9
int N, M;
int mat[MAX_NM][MAX_NM] = {
    0,
};
int virus[MAX_NM][MAX_NM] = {
    0,
};
vector<pair<int, int>> v;  // 초기 바이러스 위치 저장
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int max_safeArea = 0;

int cnt(int mat[][MAX_NM]) {
    int c = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 0)
                c++;
        }
    }
    return c;
}
void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < v.size(); i++) {
        q.push(v[i]);
    }
    while (!q.empty()) {
        pair<int, int> xy = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + xy.first;
            int ny = dy[i] + xy.second;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (virus[nx][ny] == 0) {
                    virus[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
}
void dfs(int n) {
    if (n == 3) {
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                virus[i][j] = mat[i][j];
            }
        }
        bfs();
        max_safeArea= max(cnt(virus), max_safeArea);
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mat[i][j] == 0) {
                    mat[i][j] = 1;
                    dfs(n + 1);
                    mat[i][j] = 0;
                }
            }
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 2) {
                v.push_back({i, j});
            }
        }
    }
    dfs(0);
    
    cout << max_safeArea;
}