//편집거리
/* 
 2차원 배열로 문자열끼리 하나씩 비교하면서 체크
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 5010

string str1, str2;
int dp[MAX_N][MAX_N]= {0,};

int main(){
    cin >> str1 >> str2;
    int len1 = str1.size();
    int len2 = str2.size();

    for(int i = 0; i < len1; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j < len2; j++){
        dp[0][j] = j;
    }

    for(int i = 1 ; i < len1; i++){
        for(int j = 1 ; j < len2; j++){
            if(str1[i-1] != str2[j-1]){ 
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }else{
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[len1][len2];
}