//정확한 순위
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> indegree[501], outdegree[501];
bool vis[501], re_vis[501];
int vis_cnt, re_vis_cnt;

void dfs(int cur){
    if(vis[cur])
        return;
    vis_cnt++;
    vis[cur] = true;
    for(int i =0; i < indegree[cur].size(); i++){
        dfs(indegree[cur][i]);
    }
}
void re_dfs(int cur){
    if(re_vis[cur])
        return;
    re_vis_cnt++;
    re_vis[cur] = true;
    for(int i =0; i < outdegree[cur].size(); i++){
        re_dfs(outdegree[cur][i]);
    }
}
int main(){
    cin >> N >>M;
    int a,b, result = 0;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        indegree[a].push_back(b);
        outdegree[b].push_back(a);
    }

    for(int i =0 ; i < N; i++){
        vis_cnt = 0;
        memset(vis, 0, sizeof(vis));
        dfs(i);

        re_vis_cnt = 0;
        memset(re_vis, 0, sizeof(re_vis));
        re_dfs(i);

        if(vis_cnt + re_vis_cnt == N+1){
            result++;
        }
    }
    cout << result;
}