//퇴사
//https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14501-%ED%87%B4%EC%82%AC-exjyfr5vgj
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,tmp1, tmp2;
    cin >> N;
    vector<int> T(N+2,0),P(N+2,0);
    for(int i =1; i<= N; i++){
        cin >> T[i] >> P[i];
        //cin >>tmp1 >> tmp2;
        //T.push_back(tmp1);
        //P.push_back(tmp2);
    }
    vector<int>dp(N+2,0);
    
    int result=0;
    for(int i = 1; i <= N; i++){
        // i번째 날 일하는경우
        if(i+T[i] <= N+1){   
            dp[i+T[i]] = max(dp[i] + P[i], dp[i+T[i]]);
            result = max(result, dp[i+T[i]]);
        }
        //i번째날 일x
        dp[i+1] = max(dp[i+1], dp[i]);  
        result = max(result, dp[i+1]);
    }

    cout << result<<"\n";
}