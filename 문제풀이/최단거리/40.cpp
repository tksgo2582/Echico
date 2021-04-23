//숨바꼭질
#include <bits/stdc++.h>
using namespace std;
#define MAX 20010
#define INF 1e6
int N, M;
vector<pair<int, int>> graph[MAX];
int d[MAX];

void dijk(int start){
    priority_queue<pair<int, int>> pq; // cost, 다음노드
    pq.push({0,start});
    d[start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist )  //기존경로가 현재 경로보다 최단이라면 
            continue;
        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].first;
            int cost = dist + graph[now][i].second;
            
            if(cost < d[next]){ //현재노드 거친 경로가 기존 경로보다 최단이라면
                d[next] = cost;
                pq.push({-cost, next});
            }
        }
    }
}

int main(){
    cin >> N >> M;
    int a, b;
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b;
        graph[a].push_back({b,1});
        graph[b].push_back({a,1});
    }
    fill(d, d+MAX, INF);
    
    dijk(1);    //1에서 시작

    int cnt, maxDist = 0, maxNode = 0;
    for(int i = 1 ; i <= N; i++){
        if(maxDist < d[i]){ // 최단거리가 가장 먼 노드 구하기.
            maxDist = d[i];
            maxNode = i;
            cnt = 1;
        }else if(maxDist == d[i]){
            cnt++;
        }
    }
    cout << maxNode << ' ' << maxDist << ' ' << cnt;
}