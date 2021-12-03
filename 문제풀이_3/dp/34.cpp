//34 병사 배치하기
#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> soldier;

int main(){
    cin >> N;
    int a;
    for(int i =0 ; i < N; i++){
        cin >> a;
        soldier.push_back(a);
    }
    reverse(soldier.begin(), soldier.end());
    int dp[N];
    fill(dp, dp+N, 1);
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(soldier[j] < soldier[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int result = 0;
    for(auto a : dp){
        result = max(a, result);
    }

    cout << N - result;
}