#include <bits/stdc++.h>

using namespace std;

int v,e;
int parent[100001]; // �?모테?���?

int find_parent(int x){
    if(x == parent[x]) // 루트 ?��?���? ?��?��?���?, 루트?��?���? 찾을?��까�?? ?���?
        return x;
    return find_parent(parent[x]);
}
// ?�� ?��?���? ?��?�� 집합?�� ?��치기
void unionParent(int a, int b){
    a = find_parent(a);
    b= find_parent(b);
    if(a < b)
        parent[b]=a;
    else
    {
        parent[a] = b;
    }
    
}

int main(void) {
    cin >> v >> e;

    // �θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union ������ ���� ����
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // �� ���Ұ� ���� ���� ����ϱ�
    cout << "�� ���Ұ� ���� ����: ";
    for (int i = 1; i <= v; i++) {
        cout << find_parent(i) << ' ';
    }
    cout << '\n';

    // �θ� ���̺� ���� ����ϱ�
    cout << "�θ� ���̺�: ";
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}