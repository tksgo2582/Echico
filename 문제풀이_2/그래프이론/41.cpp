//여행계획
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 510

int N, M;
int arr[MAX_N][MAX_N] = {
    0,
};
int parent[MAX_N];

int findf(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = findf(parent[a]);
}

void unionf(int a, int b) {
    a = findf(a);
    b = findf(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    cin >> N >> M;
    int tmp;
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if ( arr[i][j] == 1) {
                unionf(i, j);
            }
        }
    }

    cin >> tmp;
    int conn = findf(tmp);
    for (int i = 1; i < M; i++) {
        cin >> tmp;
        if (findf(tmp) != conn) {
            cout << "NO\n";
            return 0;
        }
        conn = findf(tmp);
    }
    cout << "YES\n";
}