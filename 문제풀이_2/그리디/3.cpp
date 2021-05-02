//문자열 뒤집기
// 1. 0을 1로 바꾸는 경우, 2. 1을 0으로 바꾸는 경우
// 1,2 두가지 경우 모두 구해보고 더 작은거 출력
#include <bits/stdc++.h>
using namespace std;

string str;
int cnt0=0, cnt1=0;

int main(){
    cin >> str;

    if(str[0]-'0' == 1){
        cnt0++;
    }else{
        cnt1++;
    }

    for(int i = 1; i < str.size(); i++){
        if(str[i-1] != str[i]){
            if(str[i]-'0' == 1){
                cnt0++;
            }
            else{
                cnt1++;
            }
        }
    }
    int result = min(cnt0, cnt1);
    cout << result << '\n';
}