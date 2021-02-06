#include <bits/stdc++.h>

using namespace std;

int V;
int indegree[501];
vector <int> graph[501];
int times[501];

void topologysort(){
    vector<int> result(V+1);
    for(int i = 1 ; i<=V; i++) // 기본시간들로 초기화
        result[i] = times[i];
    
    queue <int> q;

    for(int i =1; i<=V; i++){   // 진입차수 0인거 큐에 삽입
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i =0; i < graph[now].size(); i++){ //현재 + 다음거 듣는거 계산
            result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
            indegree[graph[now][i]] -=1;
            if(indegree[graph[now][i]] == 0)
                q.push(graph[now][i]);
        }
    }
    for(const auto &a : result)
        cout << a << '\n';
}

int main(void) {
    cin >> V;

    // 방향 그래프의 모든 간선 정보를 입력받기
    for (int i = 1; i <= V; i++) {
        // 첫 번째 수는 시간 정보를 담고 있음 
        int x;
        cin >> x;
        times[i] = x;
        // 해당 강의를 듣기 위해 먼저 들어야 하는 강의들의 번호 입력 
        while (true) {
            cin >> x;
            if (x == -1) break;
            indegree[i] += 1;
            graph[x].push_back(i);
        }
    }

    topologysort();
}