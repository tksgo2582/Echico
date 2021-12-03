//21 인구이동
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 55

int N, L, R;
int mat[MAX_N][MAX_N] = {
    0,
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool opened[MAX_N][MAX_N] = {
    0,
};  // 열려있는 건지 검사
//int cnt = 0;
int supply = 0;
int moved_day = 0;
vector<pair<int, int>> open_contury;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    open_contury.push_back({x,y});
    opened[x][y] = 1;

    supply = mat[x][y];
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            int diff = abs(mat[x][y] - mat[nx][ny]);
            if (nx < N && nx >= 0 && ny < N && ny >= 0 && opened[nx][ny] == 0) {  // 열려있는곳 x 라면
                if (L <= diff && diff <= R) {
                    cnt++;
                    supply += mat[nx][ny];
                    opened[nx][ny] = 1;
                    open_contury.push_back({nx,ny});
                    q.push({nx, ny});
                }
            }
        }
    }
    int new_supply = supply / cnt;
    for (int i = 0; i < open_contury.size(); i++) {
        int x = open_contury[i].first;
        int y = open_contury[i].second;

        mat[x][y] = new_supply;
    }
    open_contury.clear();
}
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            opened[i][j] = 0;
            //cnt = 0;
            //supply = 0;
        }
    }
    //open_contury.clear();
}
int main() {
    ios_base::sync_with_stdio;
    cin.tie();

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    while (1) {
        init();
        int check_cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (opened[i][j] == 0) {
                    bfs(i, j);
                    check_cnt++;
                }
            }
        }
        if(check_cnt >= N *N){  // 모두검사했는데 각 방마다 들어갔을경우
            break;              // 인구 이동 끝
        }
        moved_day++;
    }
    cout << moved_day;
}