//특정거리의 도시 찾기
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 30000

int N, M, K, X;
int cnt = 0;
vector<int> doro[MAX_N];
int visit[MAX_N];

void bfs(){
    queue<int> q;
    q.push(X);
    visit[X] = 0;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0 ; i < doro[now].size(); i++){
            if(visit[doro[now][i]] == -1){
                visit[doro[now][i]] = visit[now] + 1;
                q.push(doro[now][i]);
            }
        }
    }
}

int main(){
    cin >> N >> M >> K >> X;
    int a, b;
    
    for(int i = 0 ; i < M; i++ ){
        cin >> a >> b;
        doro[a].push_back(b);
    }
    fill(visit, visit+N+1, -1);
    bfs();

    //cout << count(visit, visit+N+1, K);
    int cnt = 0;
    for(int i = 1 ; i < N+1; i++){
        if(visit[i] == K){
            cnt++;
            cout << i << '\n';
        }
    }
    if(!cnt){
        cout << -1 <<'\n';
    }
    return 0;
}