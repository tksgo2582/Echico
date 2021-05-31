#include <bits/stdc++.h>
using namespace std;
#define MAX_N 21
#define INF 1e6

int N;
int sea[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int fishsize = 2;
pair<int, int> curPos, preyPos;

bool dijkstra(){
    priority_queue<pair<int ,pair<int, int>>> pq;
    pq.push({0, curPos});
    fill(&dist[0][0], &dist[N-1][N], INF);
    dist[curPos.first][curPos.second] = 0;

    vector<pair<int ,pair<int, int>>> prey;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(dist[x][y] < cost){
            continue;
        }
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx<0 || nx>=N || ny<0 || ny >=N || sea[nx][ny] > fishsize){
                continue;
            }
            int nextcost = cost + 1;
            if(dist[nx][ny] > nextcost){
                dist[nx][ny] = nextcost;
                pq.push({-nextcost, {nx,ny}});

                if(sea[nx][ny] != 0 && sea[nx][ny] < fishsize){
                    prey.push_back({nextcost,{nx,ny}} );
                } 
            }
        }
    }
    if(!prey.empty()){
        sort(begin(prey), end(prey));
        preyPos = {prey[0].second.first, prey[0].second.second};
        return true;
    }
    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sea[i][j];
            if(sea[i][j] == 9){
                curPos = {i,j};
                sea[i][j] = 0;
            }
        }
    }
    int answer = 0 , eatcnt = 0;

    while(dijkstra()){
        answer += dist[preyPos.first][preyPos.second];
        if(++eatcnt == fishsize){
            fishsize++;
            eatcnt=0;
        }
        sea[preyPos.first][preyPos.second] = 0;
        curPos = preyPos;
    }
    cout << answer << '\n';
}