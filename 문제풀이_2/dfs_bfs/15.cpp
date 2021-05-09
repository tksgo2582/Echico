// 특정 거리의 도시 찾기
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 300010

int N, M, K, X;
vector<int> graph[MAX_N];
int dist[MAX_N];

void bfs(int x){
    queue<int> q;   // 1. 초기설정 ( 시작 점 큐에 넣기, 시작점 거리 설정)
    q.push(x);
    dist[x] = 0;

    while(!q.empty()){
        int now = q.front();    // 2. 하나씩 pop
        q.pop();

        for(int i = 0; i < graph[now].size(); i++){ //3. 뺀 도시와 연결된 도로들 순회
            int next = graph[now][i];
            if(dist[next] == -1){                   //4. 순회하면서 안가본곳 
                dist[next] = dist[now]+1;           // 거리 = 현재 + 1
                q.push(next);                       //5. 큐에 넣기
            }
        }
    }
}

int main(){
    cin >> N >> M >> K >> X;
    int a,b;
    for(int i =0 ; i < M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    fill(dist, dist+N+1, -1);

    bfs(X);

    int cnt = 0;
    for(int i = 1 ; i < N+1; i++){
        if(dist[i] == K){
            cnt++;
            cout << i << '\n';
        }
    }
    if(!cnt){
        cout << -1 <<'\n';
    }
}