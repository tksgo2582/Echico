#include <bits/stdc++.h>

using namespace std;

int V, E;
int parent[100001];

vector <pair<int, pair<int ,int>>> edges; //cost, 노드 a,b
int result = 0;

int findparent(int x){
    if(x==parent[x])    //같은 루트노드면 x 출력
        return x;
    return parent[x] = findparent(parent[x]); // 루트노드 갱신
}

void unionparent(int a, int b){ 
    a = findparent(a);  //각각의 루트노드
    b = findparent(b);

    if(a<b)             //b가 더 크면 b의 루트노드는 a
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    cin >> V >> E;
                            //초기화 부분
    for(int i = 1; i <=V; i++){
        parent[i] = i;
    }

    for(int i = 0 ; i < E; i++){
        int a, b, cost;
        cin >> a >> b >>cost;
        edges.push_back({cost, {a,b}});
    }   
        sort(edges.begin(), edges.end()); //비용 오름차순으로 정렬

    for(int i =0 ; i< edges.size(); i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if(findparent(a) != findparent(b)){ //루트노드가 같지 않다면
            unionparent(a,b);   //union
            result += cost;     //연결된 비용 추가
        }
    }
    cout << result << "\n";    
}