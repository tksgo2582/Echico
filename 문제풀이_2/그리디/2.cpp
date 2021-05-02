//곱하기 혹은 더하기
/* 
    1. 문자열로 받고 0일때만 +, 나머지는 모두 *으로..
    2. 문자열을 숫자로 바꾸는 쉬운방법 - str[i] -'0'
 */
#include <bits/stdc++.h>
using namespace std;

string str;

int main(){
    cin >> str;
    int result=str[0] - '0';
    for(int i = 1 ; i < str.size(); i++){
        if(str[i] -'0' == 0 || result == 0){
            result += str[i] -'0';
        }else
            result *= str[i] -'0';
        //cout << result << '\n';
    }
    cout << result <<'\n';
}