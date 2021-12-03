//40 숨바꼭질
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20010
#define INF 1e9

int N, M;
vector <int> graph[MAX_N];
int dist[MAX_N];

void dijk(){
    priority_queue<pair<int, int>> pq;
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        int now_dist = pq.top().first;
        int node = pq.top().second;
        if(now_dist > dist[node])
            continue;
        for(int i = 0 ; i < 4; i++){

        }
    }
}
/* void init(){
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i== j){
                dist[i] = 0;
            }else{
                dist[i][j] = INF;
            }
        }
    }
}
 */
int main(){
    int A, B;
    cin >> N >> M;
    for(int i =0 ; i < M; i++){
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    dijk();
    int cnt = 0 , MAX_node = 0, dist_val=dist[0]; 
    for(int i = 1; i <= N; i++){
        if(dist_val < dist[i]){
            dist_val = dist[i];
            MAX_node = i;
            cnt = 0;
        }
        if(dist_val == dist[i]){
            cnt++;
        }
    }
    cout << MAX_node << ' ' << dist_val << ' ' << cnt;
}