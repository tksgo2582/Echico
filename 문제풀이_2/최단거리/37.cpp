//플로이드
#include <bits/stdc++.h>
using namespace std;

typedef struct bus {
    int des, cost;
} bus;

int n, m;
int graph[110][110];
vector<bus> v[100010];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else
                graph[i][j] = 1e5;
        }
    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (graph[a][b] > c)
            graph[a][b] = c;
        //v[a].push_back({b, c});
    }

    floyd();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1e5)
                cout << "0 ";
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}