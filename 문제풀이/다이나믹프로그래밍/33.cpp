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
        if(i+T[i] <= N+1){   // i 번째날 일하면 T[i] 시간 걸림... <-- 퇴사전까지 일할 수 있다면
            dp[i+T[i]] = max(dp[i] + P[i], dp[i+T[i]]); // 오늘 일하는 거랑, 오늘 일 안하고 그날 받는 돈 차이 비교
            result = max(result, dp[i+T[i]]);
        }
        //i번째날 일x
        dp[i+1] = max(dp[i+1], dp[i]);  // i번째 날 일하는거, 다음날 일하는 거 비교
        result = max(result, dp[i+1]);
    }

    cout << result<<"\n";
}