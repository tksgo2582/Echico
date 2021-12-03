//38 정확한 순위
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 510
#define INF 1e9

int N, M;
int graph[MAX_N][MAX_N];

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
}
void floyd(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <=N; i++){
            for(int j = 1; j <=N; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+ graph[k][j]);
            }
        }
    }
}
int main() {
    cin >> N >> M;
    int a, b;
    init();
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
    }
    floyd();
    int res=0;

    for(int i = 1; i <= N; i++){
        int cnt = 0;
        for(int j = 1; j<=N; j++){
            if(graph[i][j] != INF || graph[j][i] != INF){   // i->j, j->i 경로가 존재한다면, 등수를 셀수 있다.
                cnt++;
            }
        }
        if(cnt == N){
            res++;
        }
    }
    cout << res;
}