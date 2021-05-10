//연구소
// n3  -2560 까지 1초.... 
/* 
    1. dfs로 3개의 벽을 세우기
    2. 3개 세웠다면 virus 검사!... ( temp 배열 로 기존 맵 복사해서 사용...)
    3. 다시 3개 세우고 반복...

    두번의 dfs 를 구현해야 하는점이 생각 어려웠다.
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_NM 10

int N, M;
int graph[MAX_NM][MAX_NM];
int temp[MAX_NM][MAX_NM];
int result=0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void virus(int x, int y){
    for(int i = 0 ; i < 4; i ++){ // 바이러스 전염
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if(nx >= 0 && nx < N && ny >= 0 && ny < M){
            if(temp[nx][ny] == 0){
                temp[nx][ny] = 2;
                virus(nx,ny);
            }
        }
    }
}
int get_score(){    // 현재의 안전지대 계산.
    int score = 0;
    for(int i = 0; i < N; i++){
            for(int j = 0; j <M ;j++){
                if(temp[i][j] == 0){
                    score += 1;
                }
            }
        }
    return score;
}

void dfs(int cnt){

    if(cnt == 3){   // 벽 3개 라면
        for(int i = 0; i < N; i++){
            for(int j = 0; j <M ;j++){
                temp[i][j] = graph[i][j];       // 초기 맵 복사
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j <M ;j++){
                if(temp[i][j] == 2){        // 바이러스 라면
                    virus(i,j);
                }
            }
        }
        result = max(result, get_score());
        return;
    }
    else{           // 벽이 3개 아니면 
        for(int i = 0; i < N; i++){
            for(int j = 0; j <M ;j++){
                if(graph[i][j] == 0){ // 차례대로 벽 쌓아보면서 dfs
                    graph[i][j] = 1;
                    cnt++;
                    dfs(cnt);
                    cnt--;
                    graph[i][j] = 0;
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <M ;j++){
            cin >> graph[i][j];
        }
    }

    dfs(0);

    cout << result <<'\n';
}
