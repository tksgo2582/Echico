#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int N,M,start;
vector <pair<int, int>> graph[100001];
int d[100001];

void dijkstra(int start){
    d[start] = 0;
    priority_queue <pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist)
            continue;

        for(int i = 0; i < graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            if(cost <  d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }  
        }
    }
}