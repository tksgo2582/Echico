// 19번 문제
// dfs 말고 next_permutation 이용해서 해결
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int N;
//int op[4] ={0,}; // +, -, *, /
vector<int> op;
vector<int> v;
int MAX_V = -INF , MIN_V = INF;

int main(){
    cin >> N;
    int tmp;
    for(int i = 0; i <N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i = 0; i<4; i++){
        cin >> tmp;
        for(int j =0 ; j < tmp; j++ ){
            op.push_back(i);
        }
    }
    sort(op.begin(), op.end());
    do{
        int result = v[0];
        int cnt = 1;
        for(auto a : op){
            if(a == 0){
                result += v[cnt++];
            }
            if(a == 1){
                result -= v[cnt++];
            }
            if(a == 2){
                result *= v[cnt++];
            }
            if(a == 3){
                result /= v[cnt++];
            }
        }
        MAX_V = max(MAX_V, result);
        MIN_V = min(MIN_V, result);
    }while(next_permutation(op.begin(), op.end()));
    

    cout << MAX_V << '\n';
    cout << MIN_V << '\n';
}