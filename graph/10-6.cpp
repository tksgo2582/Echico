#include <bits/stdc++.h>

using namespace std;

int V,E;
int indegree[100001];       // 진입차수 저장
vector <int> graph[100001]; // 그래프 저장 벡터배열 

void topologySort(){        //위상 정렬
    vector<int> result;
    queue <int> q;

    for(int i = 1 ; i<= V; i++){    //노드 수만큼 반복
        if(indegree[i] == 0)        //진입 차수 0 이라면 큐에 삽입
            q.push(i);
    }
    while(!q.empty()){
        int now = q.front();        
        q.pop();
        result.push_back(now);

        for(int i =0 ; i< graph[now].size(); i++){  //노드에 연결된 크기만큼 반복
            indegree[graph[now][i]] -=1;            //연결되는 간선 삭제(연결노드)
            if(indegree[graph[now][i]] == 0)        // 0 이 되면 큐삽입
                q.push(graph[now][i]);
        }
    }

    for(int i = 0; i< result.size(); i++){
        cout << result[i] << ' ';
    }
}

int main(void) {
    cin >> V >> E;

    // 방향 그래프의 모든 간선 정보를 입력 받기
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); // 정점 A에서 B로 이동 가능
        // 진입 차수를 1 증가
        indegree[b] += 1;
    }

    topologySort();
}