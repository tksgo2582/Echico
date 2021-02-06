#include <bits/stdc++.h>
using namespace std;

int N;
char mat[6][6];
vector <pair<int, int>> v ,t;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool chk(pair<int,int> pt){     //선생님 시선에 닿는지 확인
    for(int i =0; i<4; i++){    
        int y = pt.first, x = pt.second;
        // while 문으로 한방향에 대해서 각각 계속 확인
        while(0 <=y+dy[i] && y +dy[i] <N && 0<=x+dx[i] && x+dx[i]<N){
            y += dy[i];
            x += dx[i];
            if(mat[y][x] == 'O')    //벽에 닿았다면 끝
                break;
            else if(mat[y][x] == 'S')   // 학생이 있다면 
                return true;
        }
    }
    return false;
}

void dfs(int len, int idx){
    if(len == 3){               //3개의 벽을 세웠다면
        for(auto i : t){
            if(chk(i)){         //선생님 좌표들 들어가서 확인
                return;         //선생님 시선에 닿는다면 그냥 함수탈출
            }
        }
        printf("YES\n");
        exit(0);
    }
    for(int i = idx; i < v.size(); i++){    //3개의 벽을 세우는 방법
        mat[v[i].first][v[i].second] = 'O';
        dfs(len + 1, i+1);
        mat[v[i].first][v[i].second] = 'X';
    }
}

int main(){
    char c;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N ; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'X'){
                v.push_back({i,j});
            }else if(mat[i][j] == 'T'){
                t.push_back({i,j});
            }
        }
    }
    dfs(0 ,0);
    printf("NO\n");
}