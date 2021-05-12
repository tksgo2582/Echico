//인구이동
/* 
    인구 이동을 맵 전체를 다 돌고 한번씩 하는듯?
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 55

int N, L, R;
int A[MAX_N][MAX_N];
int opened[MAX_N][MAX_N];
vector<pair<int, int>> v;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int result = 0;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    v.push_back({x, y});
    opened[x][y] = 1;
    int cnt = 1;
    int sum_p = A[x][y];
    while (!q.empty()) {
        pair<int, int> xy = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = xy.first + dx[i], ny = xy.second + dy[i];
            int diff = abs(A[xy.first][xy.second] - A[nx][ny]);
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            if (L <= diff && diff <= R && opened[nx][ny] == -1) {
                opened[nx][ny] = 1;
                cnt++;  // 국경 열린 나라.
                v.push_back({nx, ny});
                q.push({nx, ny});
                sum_p += A[nx][ny];
            }
        }
    }
    int flag = 0;
    int new_p = sum_p / cnt;
    for (int i = 0; i < v.size(); i++) {
        int nx = v[i].first, ny = v[i].second;
        A[nx][ny] = new_p;
        //opened[nx][ny] = -1;
        //flag = 1;
    }
    v.clear();
    /* if (flag) {
        result++;           //국경이 열린적 있다면 횟수 증가
        A[x][y] = new_p;
        opened[x][y] = -1;
        
    } */
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    while (1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                opened[i][j] = -1;
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (opened[i][j] == -1) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        if (cnt >= N * N) {
            break;
        }
        result++;
    }
    cout << result << '\n';
}