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

    // ë¶?ëª? ?…Œ?´ë¸”ìƒ?—?„œ, ë¶?ëª¨ë?? ?ê¸? ??‹ ?œ¼ë¡? ì´ˆê¸°?™”
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union ?—°?‚°?„ ê°ê° ?ˆ˜?–‰
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // ê°? ?›?†Œê°? ?†?•œ ì§‘í•© ì¶œë ¥?•˜ê¸?
    cout << "1: ";
    for (int i = 1; i <= v; i++) {
        cout << find_parent(i) << ' ';
    }
    cout << '\n';

    // ë¶?ëª? ?…Œ?´ë¸? ?‚´?š© ì¶œë ¥?•˜ê¸?
    cout << "2: ";
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}