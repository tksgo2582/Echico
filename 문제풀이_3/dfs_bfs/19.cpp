//19 연산자 끼워넣기
#include <bits/stdc++.h>
using namespace std;

int op[4] = {0,};       //+,-,*,/
int N, MAX = -1e9, MIN = 1e9;
vector<int> oprand;
vector<int> operate;

void dfs(){

}

int main(){
    cin >> N;
    oprand.assign(N,0);
    for(int i = 0 ; i < N; i++){
        cin >> oprand[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op[i];
        for(int j = 0; j < op[i]; j++){
            operate.push_back(i);
        }
    }

    //dfs();
    do{
        int answer = oprand[0];
        for(int i = 1 ; i < N; i++){
            if(operate[i-1] == 0){
                answer += oprand[i];
            }else if(operate[i-1] == 1){
                answer -= oprand[i];
            }else if(operate[i-1] == 2){
                answer *= oprand[i];
            }else if(operate[i-1] == 3){
                answer /= oprand[i];
            }
        }
        MAX = max(MAX, answer);
        MIN = min(MIN, answer);
    }while(next_permutation(operate.begin(), operate.end()));
    
    cout << MAX << "\n" << MIN;
}