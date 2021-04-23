//화성 탐사
#include <bits/stdc++.h>
using namespace std;
#define MAX 126
#define INF 1e6
int T,N;
int graph[126][126];
int d[126][126];
int dx[] = {-1, 0 ,1, 0};
int dy[] = {0, -1, 0, 1};

void dijk(){
    int x = 0, y = 0; // 시작위치
    priority_queue<pair<int, pair<int, int>>> pq; // 다익스트라 우선순위 큐.(구조체 만들어서 해도 괜찮을 듯...)
    pq.push({-graph[x][y], {x,y}});
    d[x][y] = graph[x][y];

    while(!pq.empty()){
        int dist = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(d[x][y] < dist)  // 이전에 있던 경로가 더 짧으면
            continue;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 && nx >= N && ny <0 && ny >= N)
                continue;
            int cost = dist + graph[nx][ny]; // 현재까지 이동비용 + 다른노드로 가는 비용

            if(cost < d[nx][ny]){   //현재 노드 경로가 기존보다 빠르다면
                d[nx][ny] = cost;   //업데이트
                pq.push({-cost,{nx,ny}});
            }
        }
    }
}
void init(){
    for(int i =0 ; i < N; i ++){
        for(int j = 0 ; j < N; j++){
            d[i][j] = INF;
        }
    }
}
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i =0 ; i < N; i ++){
            for(int j = 0 ; j < N; j++){
                cin >> graph[i][j];
            }
        }
        init();
        dijk();

        cout << d[N-1][N-1] << '\n';
    }
}