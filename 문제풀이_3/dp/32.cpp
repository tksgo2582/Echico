//32 정수 삼각형
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 510

int main() {
    int N;
    int tri[MAX_N][MAX_N] = {0,};

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
        }
    }
    int result = tri[N][1];
    for (int i = 0; i <= N; i++) {
        result = max(result, tri[N][i]);
    }
    cout << result;
}