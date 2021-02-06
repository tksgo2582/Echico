#include <iostream>
#include <queue>

using namespace std;

int N,M;
int mat[200][200];
int visit[200][200];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int x,int y){
    queue <pair<int, int>> q;
    q.push(make_pair(x,y));
    visit[x][y] =1;
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i =0 ; i<4; i++){
            x = nx + dx[i];
            y = ny +dy[i];
            if(x >=0 && x<N && y>=0 && y<M){
                if(mat[x][y] == 1 && visit[x][y]==0){
                    visit[x][y] = visit[nx][ny] + 1;
                    q.push(make_pair(x,y));
                }
            }

        }
    }
}

int main(){
    cin >> N>>M;
    string s;
    for(int i=0; i < N;i++){
        cin >> s;
        for(int j=0; j < M; j++)
            mat[i][j] = s[j]-'0';
    }
    bfs(0,0);

    cout<<visit[N-1][M-1];
}