#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M, start;
vector <pair<int, int>> graph[100001]; // 연결 정보들 
int d[100001];  // 최단거리테이블

void dijsktra(){
    priority_queue <pair<int, int>> pq; //비용과 출발점 저장 우선순위큐
    d[start] = 0;
    pq.push(make_pair( 0, start));  //맨 처음 

    while(!pq.empty()){
        int dist = -pq.top().first;     // 현재노드까지 비용(-)
        int now = pq.top().second;      // 현재 노드의 번호
        pq.pop();

        if( d[now] < dist)              // 현재노드까지 비용이 큐의 비용보다 낮다면 스킵
            continue;
        for(int i = 0; i < graph[now].size(); i++){ // 연결된 노드들 만큼 반복
            int cost = dist + graph[now][i].second; // 현재비용 + 연결노드 비용
            if( cost < d[graph[now][i].first] ){    // 그 비용이 더 작다면
                d[graph[now][i].first] = cost;      // 최단거리 테이블 교체
                pq.push(make_pair( -cost, graph[now][i].first));
            }                                       // 우선순위 큐에 저장
        }
    }
}