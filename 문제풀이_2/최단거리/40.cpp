// 숨바꼭질
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20010
#define INF 1e9
int N,M;
vector<pair<int,int>> graph[MAX_N];
int dist[MAX_N];

void dijkstra(){
    priority_queue<pair<int,int>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        int nowcost = -pq.top().first;
        int nownode = pq.top().second;
        pq.pop();

        if(dist[nownode] < nowcost){
            continue;
        }
        for(int i = 0 ; i < graph[nownode].size(); i++){
            int nextcost = nowcost+ graph[nownode][i].second;
            int nextnode = graph[nownode][i].first;

            if(nextcost < dist[nextnode]){
                dist[nextnode] = nextcost;
                pq.push({-nextcost, nextnode});
            }
        }
    }

}

void init(){
    for(int i =0  ; i <= N; i++){
        dist[i] = INF;
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int a,b,c;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a].push_back({b,1});
        graph[b].push_back({a,1});
    }

    init();
    dijkstra();
    
    int hide = *max_element(dist+1, dist+N+1);
    int num = find(dist+1,dist+N+1,hide) - dist;
    int cnt = count(dist+1, dist+N+1, hide);

    cout << num << ' ' << hide << ' ' << cnt <<'\n';

}