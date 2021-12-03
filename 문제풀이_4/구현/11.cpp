#include <bits/stdc++.h>
using namespace std;

int N, K, L;
queue<pair<int, char>> changer;  //변경점
queue<pair<int, int>> snake;
int matrix[101][101] = {
    0,
};  //맵
int cnt = 0;
char direction = 'R';
int mv_n; char mv_d;

char move_snake(char D, char mv_d) {
    char result;
    if (D == 'R') {
        if (mv_d == 'L') {
            result = 'U';
        } else {
            result = 'D';
        }
    } else if (D == 'L') {
        if (mv_d == 'L') {
            result = 'D';
        } else {
            result = 'U';
        }
    } else if (D == 'U') {
        if (mv_d == 'L') {
            result = 'L';
        } else {
            result = 'R';
        }
    } else if (D == 'D') {
        if (mv_d == 'L') {
            result = 'R';
        } else {
            result = 'L';
        }
    }
    return result;
}
int main() {
    //fill(matrix, matrix+10000,0);
    cin >> N >> K;
    int a, b;
    char c;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        matrix[a][b] = 2;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> a >> c;
        changer.push({a, c});
    }
    matrix[1][1] = 1;
    snake.push({1, 1});

    while (1) {
        if (!changer.empty()) {
            mv_n = changer.front().first;
            mv_d = changer.front().second;
            changer.pop();
        }
        int x, y, tx, ty;
        x = snake.back().first;
        y = snake.back().second;
        while (1) {
            tx = snake.front().first;
            ty = snake.front().second;
            cnt++;
            if (direction == 'R') {
                y++;
            } else if (direction == 'L') {
                y--;
            } else if (direction == 'U') {
                x--;
            } else if (direction == 'D') {
                x++;
            }
            if (x <= 0 || x > N || y <= 0 || y > N || matrix[x][y] == 1) {
                cout << cnt << '\n';
                return 0;
            }
            if (matrix[x][y] == 0) {
                matrix[tx][ty] = 0;
                snake.pop();
            }
            snake.push({x, y});
            matrix[x][y] = 1;
            if (mv_n == cnt) {
                direction = move_snake(direction, mv_d);
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}