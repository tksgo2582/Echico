//어두운 길
// 신장트리 - 크루스칼 알고리즘... 간선별 비용으로 정렬한 뒤, 비용작은 순으로 연결.
#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
struct doro{
    int src, des, cost;
};
doro edge[MAX];
int N, M;
int parent[MAX];
bool cmp(doro a, doro b){
    return a.cost < b.cost;
}
int findf(int a){
    if(parent[a] == a)
        return parent[a];
    return parent[a] = findf(parent[a]);
}
void unionf(int a, int b){
    a = findf(a);
    b = findf(b);

    if(a < b)
        parent[a] = b;
    else
        parent[b] = a;
}
int main(){
    cin >> N >> M;
    for(int i =1; i <= N; i++){
        parent[i] = i;
    }
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a,b,c};
    }

    sort(edge, edge + N, cmp);
    int result = 0, total = 0;
    for(auto gill : edge ){
        total += gill.cost;
        if(findf(gill.src) != findf(gill.des)){
            unionf(gill.src , gill.des);
            result += gill.cost;
        }
    }
    cout << total - result << '\n';
}