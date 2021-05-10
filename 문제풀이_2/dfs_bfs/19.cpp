//연산자 끼워넣기
/* 
    1. dfs로 현재 index와 계산 값을 들고 op별로 dfs..
 */
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int N;
int op[4] ={0,}; // +, -, *, /
vector<int> v;
int MAX_V = -INF , MIN_V = INF;

void dfs(int i , int now){
    if(i == N){
        MAX_V = max(MAX_V, now);
        MIN_V = min(MIN_V, now);
    }else{
        if(op[0] > 0){
            op[0]--;
            dfs(i + 1, now + v[i]);
            op[0]++;
        }
        if(op[1] > 0){
            op[1]--;
            dfs(i + 1, now - v[i]);
            op[1]++;
        }
        if(op[2] > 0){
            op[2]--;
            dfs(i + 1, now * v[i]);
            op[2]++;
        }if(op[3] > 0){
            op[3]--;
            dfs(i + 1, now / v[i]);
            op[3]++;
        }
    }
}


int main(){
    cin >> N;
    int tmp;
    for(int i = 0; i <N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i = 0; i<4; i++){
        cin >> op[i];
    }

    dfs(1 , v[0]);

    cout << MAX_V << '\n';
    cout << MIN_V << '\n';
}