//편집거리
#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001]={0,};    //이 정도 크기를 지역변수로 선언하면 그냥 종료...
int main(){
    
    string A,B;
    cin >> A >> B;

    for(int i = 1 ; i <= A.size(); i++){
        dp[i][0] = i;
    }
    for(int j = 1 ; j <= B.size(); j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= A.size(); i++ ){
        for(int j = 1; j <= B.size(); j++){
            if(A[i-1] == B[j-1]){ // 문자가 같을때
                dp[i][j] = dp[i-1][j-1];
            }else{                  // 문자가 다를 때
                                    //삽입(왼쪽), 삭제(위쪽), 교체(왼쪽 위) 중에서 최소 비용을 찾아 대입  
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]) )+1;
            }
        }
    }
    int result = dp[A.size()][B.size()];
    cout << result <<"\n";
}