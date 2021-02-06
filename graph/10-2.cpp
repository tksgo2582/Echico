#include <bits/stdc++.h>

using namespace std;

int v, e;
int parent[100001];

int find_parent(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find_parent(parent[x]);
}

void unionParent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a < b)
        parent[b] = a;
    else {
        parent[a] = b;
    }
}

int main(void) {
    cin >> v >> e;

    // �?�? ?��?��블상?��?��, �?모�?? ?���? ?��?��?���? 초기?��
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union ?��?��?�� 각각 ?��?��
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // �? ?��?���? ?��?�� 집합 출력?���?
    cout << "1: ";
    for (int i = 1; i <= v; i++) {
        cout << find_parent(i) << ' ';
    }
    cout << '\n';

    // �?�? ?��?���? ?��?�� 출력?���?
    cout << "2: ";
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}