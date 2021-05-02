#include <bits/stdc++.h>

#define INF 1e9
using namespace std;

int N,M;

int graph[501][501];

int main(){
    cin >> N>>M;
    for(int i =0; i< 501; i++){ // 이차원 배열 각각 초기화
        fill(graph[i], graph[i]+501 ,INF);
    }

    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <=N ; j++){
            if(i == j)
            graph[i][j] = 0;    //자기 노드로 가는곳 0으로 초기화
        }
    }

    for(int i  = 0; i <M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a][b] =c;         //경로 그래프 입력
    }

    for(int k = 1; k<=N; k++){ //모든 노드에 대해서 1~ N 까지 K를 거쳐가는 경로 구하기 
        for(int i = 1; i <=N; i++){ // 시작 노드 모두 검사
            for(int j =1; j<=N; j++){   // 도착점 노드 까지 검사
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}