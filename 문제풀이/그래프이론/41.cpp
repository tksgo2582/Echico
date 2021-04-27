//여행계획
#include <bits/stdc++.h>
using namespace std;
#define MAX 510

int N, M;
int parent[MAX];
int graph[MAX][MAX];

void init(){
    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }
}
int findf(int a){
    if(parent[a] == a)
        return parent[a];

    return parent[a] = findf(parent[a]);
}
void unionf(int a, int b){
    a = findf(a);
    b = findf(b); 
    
    parent[a] = b;
}
int main(){
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        for(int j = i; j <= N; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 1){
                unionf(i, j);
            }
        }
    }
    vector<int> city;
    int tmp, flag=0, result;
    for(int i = 0 ; i < M; i++){
        cin >> tmp;
        city.push_back(parent[tmp]);
        if(i == 0)
            continue;
        if(city[i-1] != city[i]){
            flag = 1;
            break;
        }
    }

    if(flag){
        cout << "NO"<< "\n";
    }else{
        cout << "YES" << "\n";
    }

}