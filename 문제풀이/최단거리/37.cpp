//플로이드
#include <bits/stdc++.h>
using namespace std;
#define INF 1e6

int n, m;
int graph[101][101];

int floyd(){
    for(int k = 1; k < n+1; k++){
        for(int i = 1; i < n+1; i++){
            for(int j =1; j < n+1; j++){
                graph[i][j] = min(graph[i][j] , graph[i][k]+graph[k][j]);
            }
        }
    }
}
void init(){
    for(int i = 0; i < 101; i++){
        for(int j = 0 ; j < 101; j++){
            if(i == j){
                graph[i][j] = 0;
            }else
                graph[i][j] = INF;
        }
    }
}
int main(){
    init();
    cin >> n >> m;
    int a,b,c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(graph[a][b] > c)
            graph[a][b] = c;
    }
    floyd();
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= n; j++){
            if(graph[i][j] == INF)
                cout << 0 << ' ';
            else{
                cout << graph[i][j] << ' ';
            }
        }
        cout << "\n";
    }

}