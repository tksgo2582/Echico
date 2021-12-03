//병사배치하기
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,tmp;
    vector<int> v;
    cin >> N;
    for(int i =0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    reverse(v.begin(), v.end()); // reverse 사용법
    vector<int> dp(N,1);
    
    for(int i=1; i <N;i++){
        for(int j = 0; j < i; j++)
            if(v[j] < v[i] ){   // 이전 전투력이 더 작다먼... - > 증가하는 수열이라면.
                dp[i] = max(dp[i],dp[j]+1); // 이전전투력증가횟수와 현재 전투력 증가횟수 비교.
            }
    }
    int result=0;
    for(auto a : dp){
        result = max(result, a);
    }
    cout << N-result <<"\n";
}