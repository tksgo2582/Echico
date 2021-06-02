// 아기상어
/* 
    1. 사냥할때마다 다익스트라 적용
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 21
#define INF 1e6

int N;
int sea[MAX_N][MAX_N];   // 바다
int dist[MAX_N][MAX_N];  // 거리
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int fishsize = 2;                // 물고기 크기
pair<int, int> curPos, preyPos;  //상어, 먹이감 좌표

bool dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, curPos});
    dist[curPos.first][curPos.second] = 0;

    fill(&dist[0][0], &dist[N - 1][N], INF);    // 거리배열 초기화

    vector<pair<int, pair<int, int>>> prey;     // 사냥감들 비용, 좌표 저장
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (dist[x][y] < cost) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || sea[nx][ny] > fishsize) {     //물고기의 크기가 상어보다 크면 x
                continue;
            }
            int nextcost = cost + 1;
            if (dist[nx][ny] > nextcost) {
                dist[nx][ny] = nextcost;
                pq.push({-nextcost, {nx, ny}});

                if (sea[nx][ny] != 0 && sea[nx][ny] < fishsize) {   // 상어 크기가 물고기보다 크면 먹을 수 있음
                    prey.push_back({nextcost, {nx, ny}});           
                }
            }
        }
    }
    if (!prey.empty()) {
        sort(begin(prey), end(prey));               //비용별로 정렬, 최소비용인 애 먼저 먹는다
        preyPos = {prey[0].second.first, prey[0].second.second};    // 최소비용인 물고기의 좌표저장
        return true;
    }
    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                curPos = {i, j};
                sea[i][j] = 0;
            }
        }
    }
    int answer = 0, eatcnt = 0;

    while (dijkstra()) {
        answer += dist[preyPos.first][preyPos.second];      //최소비용 plus
        if (++eatcnt == fishsize) {                         // 먹은 횟수 == 물고기크기 면 물고기 사이즈up
            fishsize++;
            eatcnt = 0;
        }
        sea[preyPos.first][preyPos.second] = 0;             // 먹은 곳 좌표 초기화
        curPos = preyPos;                                   // 현재 상어 위치 재설정
    }
    cout << answer << '\n';
}