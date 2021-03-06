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

    // λΆ?λͺ? ??΄λΈμ??, λΆ?λͺ¨λ?? ?κΈ? ?? ?Όλ‘? μ΄κΈ°?
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union ?°?°? κ°κ° ??
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // κ°? ??κ°? ?? μ§ν© μΆλ ₯?κΈ?
    cout << "1: ";
    for (int i = 1; i <= v; i++) {
        cout << find_parent(i) << ' ';
    }
    cout << '\n';

    // λΆ?λͺ? ??΄λΈ? ?΄?© μΆλ ₯?κΈ?
    cout << "2: ";
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}