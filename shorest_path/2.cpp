#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int N,M, K, X;
int gragh[101][101];

int main(){
    cin >> N >> M;
    int a,b;

    for(int i = 0; i <101; i++){
        fill(gragh[i], gragh[i]+101, INF);
    }
    for(int i = 0 ; i < 101; i++){
        for(int j = 0 ; j < 101; j++){
            if(i == j)
                gragh[i][j] = 0;
        }
    }

    for(int i =0; i <M; i++){
        cin >> a>> b;
        gragh[a][b] = gragh[b][a] = 1;
    }
    cin >> X >> K;

     for(int i = 1 ; i < N+1; i++){
        for(int j = 1 ; j < N+1; j++){
            for(int k = 1 ;k <N+1; k++){
                gragh[j][k] = min(gragh[j][k], gragh[j][i]+gragh[i][k]);
            }
        }
    }
    int distance = gragh[1][K] + gragh[K][X];

    cout << distance;
}