#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int mat[1000][1000];
int visited[1000][1000];
int dx[4]={1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int x, int y){
    queue <pair< int ,int>> q;
    visited[x][y] = 1;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i =0 ; i< 4; i++){
            x = nx +dx[i];
            y = ny + dy[i];
            if(x>=0 && x <N && y >=0 && y < M)
                if(mat[x][y] == 0 && visited[x][y] == 0){
                    q.push(make_pair(x,y));
                    visited[x][y]=1;
                }
        }

    }
}

int main(){
    string s;
    cin >> N >>M;
    for(int i=0; i < N;i++){
        cin >> s;
        for(int j=0; j < M; j++)
            mat[i][j] = s[j]-'0';
    }
    int cnt=0;
    for(int i =0; i < N; i++){
        for(int j=0; j< M; j++){
            if(mat[i][j] == 0 && visited[i][j] ==0){
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;
}