//감시 피하기
/* 
    1. 3개 벽 모두 세워보고(dfs), 감시(dfs)...
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10

int N;
char graph[MAX_N][MAX_N];
vector<pair<int, int>> T;       //선생님들 위치 저장
bool flag = 1;

bool detective() {
    bool up=0,down=0,right=0,left = 0;
    for (int i = 0; i <= T.size(); i++) {   //선생님들 시야 모두 검사
        pair<int, int> xy = T[i];
        while(xy.second > 0 && xy.second <= N){     //up
            if(graph[xy.first][xy.second] == 'S'){
                up = true;
                break;
            }
            if(graph[xy.first][xy.second] == 'O'){
                break;
            }
            xy.second++;
        }
        xy = T[i];
        while(xy.second > 0&& xy.second <= N){  //down
            if(graph[xy.first][xy.second] == 'S'){
                down = true;
                break;
            }
            if(graph[xy.first][xy.second] == 'O'){
                break;
            }
            xy.second--;
        }
        xy = T[i];
        while(xy.first > 0&& xy.first <= N){    //left
            if(graph[xy.first][xy.second] == 'S'){
                right = true;
                break;
            }
            if(graph[xy.first][xy.second] == 'O'){
                break;
            }
            xy.first++;
        }
        xy = T[i];
        while(xy.first > 0&& xy.first <= N){    //right
            if(graph[xy.first][xy.second] == 'S'){
                left = true;
                break;
            }
            if(graph[xy.first][xy.second] == 'O'){
                break;
            }
            xy.first--;
        }
        if(up||down||left||right){
            flag = true;
            //cout << "N " ;
            return flag;
        }else{
            flag = false;
            //cout << "yes";
        }
    }
    return flag;
}

void dfs(int cnt) {
    if (cnt == 3) {
        detective();        // 선생님들 감시 시작.
        return;
    } else {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][j] == 'X') {
                    graph[i][j] = 'O';
                    cnt++;
                    dfs(cnt);
                    cnt--;
                    graph[i][j] = 'X';
                    if(flag == 0){      // 감시망 피할 수 있다면 더이상 감시 xx
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'T') {
                T.push_back({i, j});
            }
        }
    }

    dfs(0);
    if (!flag)
        cout << "YES\n";
    else {
        cout << "NO\n";
    }
}