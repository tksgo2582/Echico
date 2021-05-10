//경쟁적 전염
/* 
    1. 바이러스 벡터에 받고, 낮은순으로 정렬
    2. 정렬된 바이러스 벡터 큐에 넣어주고, bfs
    3. 특정 시간 됐을 때, 종료 후 원하는 좌표의 바이러스 출력!.
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 210
typedef struct virus{
    int kind, time, x, y;
}virus;

int N,K, S, X, Y;
int graph[MAX_N][MAX_N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1}; 
queue <virus> q;
vector <virus> v;

void bfs(){
    while(!q.empty()){
        virus now = q.front();
        q.pop();
        if(now.time >= S){   //특정시간 지났을 때 종료..
            break;
        }
        for(int i =0 ; i < 4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if(nx > 0 && nx <= N && ny > 0 && ny <= N){
                if(graph[nx][ny] == 0){
                    graph[nx][ny] = now.kind;
                    q.push({now.kind, now.time+1, nx, ny});
                }
            }
        }
    }
}
bool comp(virus v1, virus v2){      //바이러스 정렬 
    return v1.kind < v2.kind; 
}
int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> graph[i][j];
            if(graph[i][j] > 0){
                v.push_back({graph[i][j], 0, i, j});        // 항상 바이러스가 순서대로 들어오지 않는 점 생각!!!.
            }
        }
    }
    sort(v.begin(), v.end(), comp); //벡터에 바이러스들 받아서 낮은순으로 정렬.
    for(auto a: v){
        q.push(a);                  // 정렬된 바이러스 q에 넣어준다
    }
    cin >> S >> X >> Y;

    bfs();

    cout << graph[X][Y] << '\n';

}