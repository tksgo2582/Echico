#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9 // 무한대 값

using namespace std;

int N,M, start;

vector <pair<int, int>> graph[100001];
bool visited[100001];
int d[100001];
// 방문하지 않은 노드 중에서, 가장 최단거리가 짧은 노드의 번호를 반환
int GetSmallestNode(){
    int min_value = INF;
    int index = 0;
    for(int i = 1; i<= N; i++){
        if(d[i] < min_value && !visited[i]){ //거리가 짧고 방문x
            min_value = d[i];                //인덱스 저장
            index = i;
        }
    }
    return index;
}

void dijkstra(int start){
    d[start] = 0;
    visited[start] = true;
    for(int i =0 ; i< graph[start].size(); i++){
        d[graph[start][i].first] = graph[start][i].second;
    }
    for(int i =0; i < N-1; i++){
        int now = GetSmallestNode(); // 방문하지 않은 최단거리 인덱스 반환
        visited[now] = true;    

        for(int j =0 ; j < graph[now].size(); j++){
            int cost = d[now] + graph[now][j].second; // 현재노드를 거쳐 가는 비용 계산
            if(cost < d[graph[now][j].first]){ 
                d[graph[now][j].first] = cost; //
            }
        }
    }
}

int main(void) {
    cin >> N >> M >> start;

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[a].emplace_back(make_pair(b, c));
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill_n(d, 100001, INF);
    
    // 다익스트라 알고리즘을 수행
    dijkstra(start);

    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= N; i++) {
        // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (d[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else {
            cout << d[i] << '\n';
        }
    }
}