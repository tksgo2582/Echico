//정확한 순위
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <int> v[510];
int graph[510][510];

void floyd(){
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
}

int main(){
    cin >> N >> M;
    int a,b;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else
                graph[i][j] = 1e5;
        }
    }
    for(int i = 1; i <= M; i++){
        cin >> a>>b;
        graph[a][b] = 1;
    }

    floyd();   
    int result= 0;
    for (int i = 1; i <= N; i++) {
        int cnt=0;
        for (int j = 1; j < N; j++) {
            if(graph[i][j] != 1e5 || graph[j][i] != 1e5){
                cnt++;
            }
        }
        if(cnt == N){
            result++;
        }
    }
    cout << result << '\n';
}