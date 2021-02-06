#include <bits/stdc++.h>

using namespace std;

int N, K, L;
vector <pair<int, char>> v;
int mat[101][101];
int dx[4] = {0,1,0,-1};     //동서남북 이동
int dy[4] = {1,0,-1,0};

int turn(int direction, char c){ //어느방향으로 돌지 선택
    if(c == 'L')    //왼쪽
        direction = (direction == 0)? 3: direction -1;
    else{
        direction = (direction + 1) % 4;
    }
    return direction;
}

int start_game(){
    int cnt=0;
    int length = 1;
    int x = 1, y = 1;
    int direction = 0;
    int index = 0;
    queue <pair<int, int>> q;
    q.push({x,y});
    while(1){
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(1<=nx && nx <= N && 1 <=ny && ny <= N and mat[nx][ny] !=2){
            if(mat[nx][ny] == 1 ){
                mat[nx][ny] == 2;
                q.push({nx, ny});
            }else if(mat[x][y] == 0){
                mat[nx][ny] == 2;
                q.push({nx, ny});
                int px = q.front().first;
                int py = q.front().second;
                q.pop();
                mat[px][py] = 0;
            }
        }else{
            cnt+=1;
            break;
        }
        x = nx;
        y = ny;
        cnt+=1;
        if(index < 1 && cnt == v[index].first){
            direction = turn(direction, v[index].second);
            index++;
        }
    }
    return cnt;
}

int main(){
    cin >> N >> K;
    int x ,y;
    for(int i =0; i< K; i++){
        cin >> x >> y;
        mat[x][y] = 1;
    }
    cin >> L;
    for(int i =0 ; i < L; i++){
        cin >> x >> y;
        v.emplace_back(make_pair(x,y));
    }
    mat[1][1] = 2;
    int result = start_game();
    cout << result;
}