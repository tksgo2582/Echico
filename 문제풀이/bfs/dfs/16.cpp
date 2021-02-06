#include <bits/stdc++.h>
using namespace std;

int N, M;
int mat[8][8];
int temp[8][8];
int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 0;

void virus(int x, int y){
    for(int i =0; i< 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<M)
            if(temp[nx][ny] == 0){
                temp[nx][ny] =2;
                virus(nx,ny);
            }
    }
}
int get_score(){
    int score = 0;
    for(int i = 0; i < N; i++){
        for(int j =0 ;j < M; j++){
            if(temp[i][j] == 0)
                score += 1;
        }
    }
    return score;
}

void dfs(int count){
    if(count == 3){                 //울타리를 3개 모두 세웠다면
        for(int i = 0; i < N; i++){ //temp 배열에 복사
            for(int j =0 ;j < M; j++){
                temp[i][j] = mat[i][j];
            }
        }
        for(int i = 0; i < N; i++){
            for(int j =0 ;j < M; j++){
                if(temp[i][j] == 2){     // 바이러스 채우기
                    virus(i,j);
                }
            }
        }
        result = max(result, get_score()); // 결과값 비교
        return;   //종료조건
    }
    for(int i = 0; i < N; i++){         // 울타리 3개 세우는 부분
        for(int j =0 ;j < M; j++){
            if(mat[i][j]==0){
                mat[i][j] = 1;          
                count += 1;             // 1개 세우고 재귀
                dfs(count);
                mat[i][j] = 0;
                count -= 1;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0 ; i< N; i ++){
        for(int j =0 ;j < M; j++){
            cin >> mat[i][j];
        }
    }
    dfs(0);
    cout << result;
}