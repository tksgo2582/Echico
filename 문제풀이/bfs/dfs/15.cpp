//특정거리의 도시찾기 18352번
#include <bits/stdc++.h>
using namespace std;
#define MAX 300001

int N, M, K, X;
vector<int> graph[MAX];     //그래프 형식
vector<int> dist(MAX, -1);  //거리

void bfs(int x){
    queue <int> q;
    q.push(x);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i =0; i < graph[now].size(); i++){ //현재 노드에서 갈 수 있는 곳만큼
            int nextNode = graph[now][i];           
            if(dist[nextNode] == -1){
                dist[nextNode] = dist[now]+1;
                q.push(nextNode);
            }
        }
    }
}
int main(){
    cin >> N >> M >> K >> X;
    int x, y;
    for(int i =0; i< M; i++){
        cin >> x >> y;
        graph[x].emplace_back(y);
    }
    dist[X] = 0;
    bfs(X);

    //sort(dist.begin(), dist.end());
    bool flag = 0;
    for(int i = 1; i <= N; i++){
        if(dist[i] == K){
            cout << i << "\n";
            flag = 1;
        }
    }
    if(flag == 0)
        cout << -1;
}



