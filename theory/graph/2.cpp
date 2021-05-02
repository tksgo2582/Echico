#include <bits/stdc++.h>

using namespace std;

int V, E, M;
vector<pair<int, pair<int, int>>> edges;  //cost, 노드 a,b
int parent[100001];

int find_parent(int x) {        //루트노드 찾는 함수
    if (parent[x] == x)
        return x;
    return parent[x] = find_parent(parent[x]);
}

int union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main() {
    cin >> V >> M;
    int op, a, b;

    for (int i = 1; i <= V; i++) { //!!!중요 루트 노드 초기화 부분
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> op >> a >> b;
        if (op == 0) {
            union_parent(a, b);
        } else {
            if (find_parent(a) == find_parent(b))
                cout << "YES" << "\n";
            else {
                cout << "NO" << "\n";
            }
        }
    }
}