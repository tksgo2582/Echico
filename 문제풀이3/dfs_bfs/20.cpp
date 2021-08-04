//20 감시 피하기
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 7

int N;
char mat[MAX_N][MAX_N];
vector<pair<int, int>> teacher;
vector<pair<int, int>> student;
char copyed[MAX_N][MAX_N];
bool can_flag = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool gamsi() {
    for (int i = 0; i < teacher.size(); i++) {
        pair<int, int> look = teacher[i];
        for (int j = 0; j < 4; j++) {
            int x = look.first;
            int y = look.second;
            for (int k = 0; k < N; k++) {
                x += dx[j];
                y += dy[j];
                if (x >= 0 && x < N && y >= 0 && y < N) {
                    if (copyed[x][y] == 'O') {
                        break;
                    }
                    if (copyed[x][y] == 'S') {
                        return false;
                    }
                }
            }
        }
    }
    can_flag = true;
    return true;
}

void dfs(int n) {
    if (n >= 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                copyed[i][j] = mat[i][j];
            }
        }
        gamsi();
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 'X') {
                    mat[i][j] = 'O';  // 기둥세우기
                    dfs(n + 1);
                    mat[i][j] = 'X';
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie();

    cin >> N;
    char a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'T') {
                teacher.push_back({i, j});
            }
            if (mat[i][j] == 'S') {
                student.push_back({i, j});
            }
        }
    }
    dfs(0);

    if (can_flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}