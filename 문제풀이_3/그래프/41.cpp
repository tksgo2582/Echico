//41 여행계획
#include <bits/stdc++.h>
using namespace std;
#define MAX_NM 510

int N, M;
int graph[MAX_NM][MAX_NM];
int parent[MAX_NM] = {0,};

int findf(int a){
    if(a == parent[a]){
        return a;
    }

    return parent[a] = findf(parent[a]);
}

void unionf(int a, int b){
    a = findf(a);
    b = findf(b);

    if(a<b){
        parent[a] = b;
    }else{
        parent[b] = a;
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 1){
                unionf(i, j);
            }
        }
    }
    int travel, par;
    for(int i = 0 ; i < M; i++){
        cin >> travel;
        if(i == 0){
            par = parent[travel];
        }
        if(par != parent[travel]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}