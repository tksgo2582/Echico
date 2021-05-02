#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <pair<int , pair<int, int>>> v;
int parent[100001];

int find_parent(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a<b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}
int result=0;
int last;
int main(){
    cin >> N >> M;
    int a, b, cost;
    for(int i =1; i<= N;i++){
        parent[i] = i;
    }

    for(int i =0; i < M ;i++){
        cin >> a >> b >> cost;
        v.push_back({cost, {a,b}});
    }
    sort(v.begin(), v.end());

    for(int i =0 ; i < v.size() ; i++){
        cost = v[i].first;
        a = v[i].second.first;
        b = v[i].second.second;

        if(find_parent(a)!= find_parent(b)){
            union_parent(a,b);
            result += cost;     // 연결되는 간선의 비용들 저장
            last = cost;    //연결된 간선중 가장 비용이 높은 간선 저장
        }
    }
    cout << result - last;
}