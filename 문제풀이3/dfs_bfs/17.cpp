//17 경쟁적 전염
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 210
#define MAX_K 1010

int N, K, S, X, Y;
int mat[MAX_N][MAX_N];
vector<pair<int,int>> virus[MAX_K];
int dx[4] = {1,0,-1,0}; int dy[4] = {0,1,0,-1};

void bfs(){
    queue<pair<int, pair<int, int>>> q;
    for(int i = 1; i <= K; i++){
        for(int j = 0; j < virus[i].size(); j++){
            q.push({0,virus[i][j]});
        }
    }
    while(!q.empty()){
        int time = q.front().first;
        if(time >= S)
            break;
        int x = q.front().second.first; int y = q.front().second.second;
        q.pop();
        for(int i = 0; i< 4; i++){
            int nx = dx[i] + x; int ny = dy[i] + y;
            if(nx > 0 && nx <= N && ny >0 && ny <= N && mat[nx][ny] == 0){
                mat[nx][ny] = mat[x][y];
                q.push({time+1, {nx,ny}});
            }
        }
    }
}

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j =1; j <= N; j++){
            cin >> mat[i][j];
            if(mat[i][j] != 0){
                virus[mat[i][j]].push_back({i,j});
            }
        }
    }
    cin >> S >> X >> Y;
    
    bfs();
    
    cout << mat[X][Y];
    
}