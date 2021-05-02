#include <bits/stdc++.h>

using namespace std;

int v,e;
int parent[100001]; // 遺?紐⑦뀒?씠釉?

int find_parent(int x){
    if(x == parent[x]) // 猷⑦듃 ?끂?뱶媛? ?븘?땲?씪硫?, 猷⑦듃?끂?뱶瑜? 李얠쓣?븣源뚯?? ?옱洹?
        return x;
    return find_parent(parent[x]);
}
// ?몢 ?썝?냼媛? ?냽?븳 吏묓빀?쓣 ?빀移섍린
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

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union 연산을 각각 수행
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // 각 원소가 속한 집합 출력하기
    cout << "각 원소가 속한 집합: ";
    for (int i = 1; i <= v; i++) {
        cout << find_parent(i) << ' ';
    }
    cout << '\n';

    // 부모 테이블 내용 출력하기
    cout << "부모 테이블: ";
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}