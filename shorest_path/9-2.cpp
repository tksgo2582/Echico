#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define INF 1e9

using namespace std;

int N,M,start;
vector <pair<int, int>> graph[100001]; // 지도 정보
int d[100001];                          // 최단거리 테이블

void dijkstra(int start){
    priority_queue <pair<int, int>> pq; //우선순위 큐
    pq.push(make_pair(0,start));        //시작
    d[start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;     //현재 노드까지 비용
        int now = pq.top().second;      //현재 노드 정보
        pq.pop();

        if(d[now] < dist)               //현재노드까지 비용이 이미 더 적다면 스킵 
            continue;
        for(int i =0; i < graph[now].size(); i++){ //연결된 노드수 만큼
            int cost = dist + graph[now][i].second; //현재비용 + 갈 노드 비용
            if(cost < d[graph[now][i].first]){ //미래비용이 현재 비용보다 더 적을 경우만
                d[graph[now][i].first] = cost; // 비용 변경
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}