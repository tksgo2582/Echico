#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int op[4] = {
    0,
};  //+ - * /
int minv=1e9,maxv=-1e9;

void dfs(int num, int result) {
    if(num == N){   //모든 연산 수행 후 min,max 값 계산
        minv = min(minv , result);
        maxv = max(maxv, result);
    }
    else{               //아직 연산중
        if(op[0] > 0){  // + 부분으로 재귀
            op[0] -=1;
            dfs(num + 1, result +v[num] );
            op[0] +=1;
        }
        if(op[1] > 0){  // -
            op[1] -=1;
            dfs(num + 1, result -v[num] );
            op[1] +=1;
        }
        if(op[2] > 0){  // *
            op[2] -=1;
            dfs(num + 1, result *v[num] );
            op[2] +=1;
        }
        if(op[3] > 0){  // /
            op[3] -=1;
            dfs(num + 1, result /v[num] );
            op[3] +=1;
        }
    }
}

int main() {
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    dfs(1, v[0]);
    cout << maxv <<'\n' << minv;
}